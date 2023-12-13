#include <iostream>
#include <string>
#include <vector>
#include <functional>

#include "tooldata.h"
#include "log.h"


using CallbackFunc = std::function<void()>;
// 测试回调信息打印
void info_test_func(const std::string& title, CallbackFunc callback)
{
    std::cout << "------" << "[" << title << ":test]" \
        << "------" << std::endl;
    callback();
    std::cout << "--------------end--------------\n\n";
}



// 树测试
void test_tree_insrt()
{
    data_tool::tree::AVLTree<int> avlTree;
    
    // 插入节点
    avlTree.root = avlTree.insertNode(avlTree.root, 5);
    avlTree.root = avlTree.insertNode(avlTree.root, 3);
    avlTree.root = avlTree.insertNode(avlTree.root, 7);
    avlTree.root = avlTree.insertNode(avlTree.root, 2);
    avlTree.root = avlTree.insertNode(avlTree.root, 4);
    avlTree.root = avlTree.insertNode(avlTree.root, 6);
    avlTree.root = avlTree.insertNode(avlTree.root, 8);
    
    // 中序遍历
    avlTree.inorderTraversal(avlTree.root);
    std::cout << std::endl;
}

void test_tree_delete()
{
    data_tool::tree::AVLTree<std::string> avlTree;
   
    // 插入节点
    avlTree.root = avlTree.insertNode(avlTree.root, "banana");
    avlTree.root = avlTree.insertNode(avlTree.root, "apple");
    avlTree.root = avlTree.insertNode(avlTree.root, "cherry");
    avlTree.root = avlTree.insertNode(avlTree.root, "grape");
    avlTree.root = avlTree.insertNode(avlTree.root, "fig");
    
    // 中序遍历
    avlTree.inorderTraversal(avlTree.root);
    std::cout << std::endl;

    // 删除节点
    avlTree.root = avlTree.deleteNode(avlTree.root, "apple");
    // 中序遍历
    avlTree.inorderTraversal(avlTree.root);
    std::cout << std::endl;

    // 删除节点
    //avlTree.root = avlTree.deleteNode(avlTree.root, "apple");
    avlTree.root = avlTree.deleteNode(avlTree.root, "fig");

    // 中序遍历
    avlTree.inorderTraversal(avlTree.root);
    std::cout << std::endl;
}



// 链表测试
void test_list_init()
{
    data_tool::list::CustomLinkedList<int> list;
    list.print("test1");
    list.Clear();
    list.print("test1");
}

void test_list_add()
{
    data_tool::list::CustomLinkedList<int> list;
    int data = 42;
    int key = 1;

    list.Add(key, data);
    list.print("test2, Add");

    list.Add(key, data); // Adding the same key again should fail

    list.Delete(key);
    list.print("test2, Del");

    list.Delete(key); // Deleting a non-existent key should fail
    list.print("test2, Del");
}

void test_list_find()
{
    data_tool::list::CustomLinkedList<std::string> list;
    std::string data1 = "42";
    std::string data2 = "100";
    int key1 = 1;
    int key2 = 2;

    list.Add(key1, data1);
    list.Add(key2, data2);

    std::string  foundData1;
    std::string  foundData2;

    list.Find(key1, foundData1);
    list.Find(key2, foundData2);

    std::cout << foundData1 <<std::endl;
    std::cout << foundData2 <<std::endl;
}

void test_list_thread()
{
    data_tool::list::CustomLinkedList<std::string> list;
    std::vector<std::thread> threads;
    const int num_threads = 10;
    const int num_adds = 100;

    // 启动多个线程进行添加操作
    for (int i = 0; i < num_threads; i++) {
        threads.emplace_back([&list]() {
            for (int j = 0; j < num_adds; j++) {
                std::string data = "String_" + std::to_string(j);
                list.Add(j, data);
            }
        });
    }

    //list.print();

    // 等待所有线程完成
    for (auto& thread : threads) {
        thread.join();
    }

    std::cout << list.GetSize() <<std::endl;

    // 启动多个线程进行删除操作
    threads.clear();
    for (int i = 0; i < num_threads; i++) {
        threads.emplace_back([&list, &i]() {
            for (int j = 0; j < num_adds; j++) {
                list.Delete(j);
            }
        });
    }

    // 等待所有线程完成
    for (auto& thread : threads) {
        thread.join();
    }

    std::cout << list.GetSize() <<std::endl;
}

void test_list_clear()
{
    data_tool::list::CustomLinkedList<std::string> list(10, true);
    const int num_adds = 12;
    for (int i = 0; i < num_adds; i++) {
        std::string data = "String_" + std::to_string(i);
        list.Add(i, data);
    }
    list.print();

    list.Clear();
    list.print("clear");

    for (int i = 0; i < num_adds; i++) {
        std::string data = "String_" + std::to_string(i);
        list.Add(i, data);
    }
    list.print("add");
    std::cout << list.GetSize() <<std::endl;

    for (int i = 0; i < num_adds; i++) {
        if(i%2){
            list.Delete(i);
        }
        std::string data = "String_" + std::to_string(i);
        list.Add(i+8, data);
    }
    list.print("change");
}



// 日志测试
void test_log()
{
    log_tool::log_test();
    log_tool::log(1, "log:", 45);
}


// 
int main(int argc, char *argv[]) 
{
    // 树
    info_test_func("test_tree_insrt",  test_tree_insrt);
    info_test_func("test_tree_delete", test_tree_delete);

    // 表
    info_test_func("test_list_init",   test_list_init);
    info_test_func("test_list_add",    test_list_add);
    info_test_func("test_list_find",   test_list_find);
    info_test_func("test_list_thread", test_list_thread);
    info_test_func("test_list_clear",  test_list_clear);

    // log
    info_test_func("test_log", test_log);
   
    return 0;
}