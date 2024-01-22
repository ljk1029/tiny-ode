#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <time.h>

#include "tool_data.h"
#include "tool_sort.h"
#include "log.h"


using CallbackFunc = std::function<void()>;
// 测试回调
int func_print(const std::string& title, CallbackFunc callback)
{
    std::cout << "======" << "[" << title << " test]" << "=====" << std::endl;
    callback();
    std::cout << "--------[test end]--------\n\n";
    return 0;
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

/**
 * 算法测试
*/
std::vector<std::vector<int>> genrate_rand_array()
{
    std::vector<std::vector<int>> ret;
    // 使用当前时间作为随机数生成器的种子
    srand((unsigned) time(NULL));
    //int n = rand()%20+1;
    //int m = rand()%20+1;
    int n = 5, m = 7;
    std::cout <<  "n: " << n << " m: " << m << std::endl;
    ret.resize(n);
    for(int i=0; i<n; i++)
    {
        std::cout << "[ ";
        ret[i].reserve(m);
        for(int j=0; j<m; j++)
        {
            int t = rand()%2;
            ret[i].push_back(t);
            std::cout << t << ", ";
        }
        std::cout << " ]" << std::endl;
    }
    return ret;
}

// 算法测试
void test_DFS_BFS()
{
    std::vector<std::vector<int>> array = genrate_rand_array();
    /* std::vector<std::vector<int>> array = {
        {1, 1, 1, 0, 1, 1, 0},
        {1, 1, 1, 1, 1, 0, 0},
        {0, 0, 0, 1, 0, 1, 0},  
        {1, 0, 0, 1, 0, 0, 0},  
        {0, 1, 0, 1, 1, 1, 0}
    }; */
    std::cout << "DFS find path result: " << sort_tool::DFS(array) << std::endl;
    std::cout << "BFS find path result: " << sort_tool::BFS(array) << std::endl;
}

void sort_print(const int array[], int len)
{
    for(int i=0; i<len; i++)
        std::cout << array[i] << ' ';
    std::cout << std::endl;
}

// 
void test_sort_algorithm()
{
#define SORT_SIZE 10
    const int number[SORT_SIZE] = {95, 45, 15, 78, 84, 51, 24, 12, 89, 21};
    int sort1[SORT_SIZE], sort2[SORT_SIZE], sort3[SORT_SIZE], sort4[SORT_SIZE],
        sort5[SORT_SIZE], sort6[SORT_SIZE], sort7[SORT_SIZE], sort8[SORT_SIZE]; 
    std::copy(number, number+SORT_SIZE, sort1);
    std::copy(number, number+SORT_SIZE, sort2);
    std::copy(number, number+SORT_SIZE, sort3);
    std::copy(number, number+SORT_SIZE, sort4);
    std::copy(number, number+SORT_SIZE, sort5);
    std::copy(number, number+SORT_SIZE, sort6);
    std::copy(number, number+SORT_SIZE, sort7);
    std::copy(number, number+SORT_SIZE, sort8);

    sort_print(sort1, SORT_SIZE);
    sort_tool::bubble_sort(sort1, SORT_SIZE);
    sort_print(sort1, SORT_SIZE);

    sort_print(sort2, SORT_SIZE);
    sort_tool::insert_sort(sort2, SORT_SIZE);
    sort_print(sort2, SORT_SIZE);

    sort_print(sort3, SORT_SIZE);
    sort_tool::quick_sort(sort3, 0, SORT_SIZE-1);
    sort_print(sort3, SORT_SIZE);

    sort_print(sort4, SORT_SIZE);
    sort_tool::select_sort(sort4, SORT_SIZE);
    sort_print(sort4, SORT_SIZE);
}

char *getCmdOption(char **begin, char **end, const std::string &option) {
    char **itr = std::find(begin, end, option);
    if (itr != end && ++itr != end) {
        return *itr;
    }
    return nullptr;
}

bool cmdOptionExists(char **begin, char **end, const std::string &option) {
    return std::find(begin, end, option) != end;
}

// 测试函数入口
int main(int argc, char *argv[]) 
{
    char *cases_run = getCmdOption(argv, argv + argc, "-case");
    std::string cases_string;
    if (cases_run) {
        cases_string = cases_run;
    }
    
    // log
    func_print("test_log", test_log);

    // 树
    if (cases_run == nullptr || cases_string.find("tree") != std::string::npos) {
        func_print("test_tree_insrt",  test_tree_insrt);
        func_print("test_tree_delete", test_tree_delete);
    } 
    // 表
    if (cases_run == nullptr || cases_string.find("list") != std::string::npos) {
        func_print("test_list_init",   test_list_init);
        func_print("test_list_add",    test_list_add);
        func_print("test_list_find",   test_list_find);
        func_print("test_list_thread", test_list_thread);
        func_print("test_list_clear",  test_list_clear);
    } 
    // 搜索
    if (cases_run == nullptr || cases_string.find("sort") != std::string::npos) {
        func_print("test_DFS_BFS",     test_DFS_BFS);
        func_print("test_sort_algorithm", test_sort_algorithm);
        
    } 
    return 0;
}