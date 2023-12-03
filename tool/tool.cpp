#include <iostream>
#include <string>
#include <vector>
#include <functional>

#include "datatool.h"
#include "log.h"


using CallbackFunc = std::function<void()>;

// 测试回调
void test_func(const std::string& title, CallbackFunc callback)
{
    std::cout << "------" << "[" \
        << title << ":test]" 
        << "------" << std::endl;
    callback();
    std::cout << "--------------end--------------\n\n";
}



// 树测试
void tree_test1()
{
    data_tool::AVLTree<int> avlTree;
    
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

void tree_test2()
{
    data_tool::AVLTree<std::string> avlTree;
   
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
void list_test1()
{
    data_tool::CustomLinkedList<int> list;
    list.print("test1");
    list.Clear();
    list.print("test1");
}

void list_test2()
{
    data_tool::CustomLinkedList<int> list;
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

void list_test3()
{
    data_tool::CustomLinkedList<std::string> list;
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


void list_test4()
{
    data_tool::CustomLinkedList<std::string> list;
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


void list_test5()
{
    data_tool::CustomLinkedList<std::string> list(10, true);
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
void log_test()
{
    log_tool::log_test();
    log_tool::log(1, "log:", 45);
}


// 
int main(int argc, char *argv[]) 
{
    // 树
    test_func("tree_test1", tree_test1);
    test_func("tree_test2", tree_test2);

    // 表
    test_func("list_test1", list_test1);
    test_func("list_test2", list_test2);
    test_func("list_test3", list_test3);
    test_func("list_test4", list_test4);
    test_func("list_test5", list_test5);

    // log
    test_func("log_test", log_test);
   
    return 0;
}