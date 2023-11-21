/**
 * 文件名: Xxx.c
 * 作者: ljk
 * 创建时间: 2023-11-21
 * 文件描述: c++ list数据结构 树结构 gtest
 * 版本: V 1.0.0
 */
#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <utility>


/* 命令空间*/
namespace ltest{

// 一、双向链表存储
// 锁
std::mutex mtx;
using KEY_TYPE = long;

template<typename T>
struct _list
{
    struct _list* prev;  // 向前指针
    struct _list* next;  // 向后指针
    KEY_TYPE key;   // 键值
    T data;         // 数值
};

template<typename T>
class clist{
public:
    explicit clist(int max_size = 512, bool log = false):list_head{nullptr},list_tail{nullptr},
        list_cur_size{0} { list_max_size = max_size; log_switch = log; }
    ~clist(){ Clear(); }

    int GetSize();
    int Clear();
    int Add(KEY_TYPE key, T data);
    int Delete(KEY_TYPE key);
    
    int Find(KEY_TYPE key, T &data);

    // 测试环境下使用，这个未加锁
    void print(std::string title = "");
    
private:
    _list<T>* Find(KEY_TYPE key); // 类内部使用，未加锁
    template<typename... Args>
    void PrintInfo(const Args&... args) {
        if(log_switch){
            std::cout << "Info: ";
            ((std::cout << args), ...);
            std::cout << std::endl;
        }
    }

    bool log_switch;  // log 打印开关
    _list<T>* list_head;
    _list<T>* list_tail;
    int list_max_size;
    int list_cur_size;
};

// get list current size
template<typename T>
int clist<T>::GetSize(){
    return list_cur_size;
}

// clear all elements
template<typename T>
int clist<T>::Clear(){
    std::unique_lock<std::mutex> lock(mtx);
    while(list_head)
    {
        _list<T>* temp = list_head;
        list_head  = list_head->next;
        delete temp;
    }
    list_tail = nullptr;
    list_cur_size = 0;
    return true;
}

// add element to list
template<typename T>
int clist<T>::Add(KEY_TYPE key, T data){
    int ret = false;
    std::unique_lock<std::mutex> lock(mtx);
    if(list_cur_size >= list_max_size){
        PrintInfo("Add failed list is full!:");
        return ret;
    }

    if(Find(key) == nullptr)
    {
        _list<T>* temp = new _list<T>;
        temp->next = nullptr;
        temp->prev = nullptr;
        temp->key  = key;
        temp->data = std::move(data);
        if(list_head == nullptr){
            list_head = temp;
            list_tail = temp;
        }
        else{
            list_tail->next = temp;
            temp->prev = list_tail;
            list_tail = list_tail->next;
        }
        list_cur_size++;
        ret = true;
    }
    else
    {
        PrintInfo("Add failed key is exist!:", key, data);
    }
    return ret;
}

// delete element from list
template<typename T>
int clist<T>::Delete(KEY_TYPE key){
    int ret = false;
    std::unique_lock<std::mutex> lock(mtx);
    _list<T>* temp = Find(key) ;
    if(temp != nullptr)
    {
        if(temp->prev == nullptr)
        {
            if(temp->next == nullptr){
                list_head = nullptr;
                list_tail = nullptr;
            }
            else{
                list_head = temp->next;
                list_head->prev = nullptr;
            }
        }
        else if(temp->next == nullptr)
        {
            list_tail = temp->prev;
            list_tail->next = nullptr;
        }
        else{
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }
        delete temp;
        list_cur_size--;
        ret = true;
    }
    else{
        PrintInfo("key no exsit!:", key);
    }
    return ret;
}

// find element in list
template<typename T>
_list<T>* clist<T>::Find(KEY_TYPE key){
    _list<T>* ret = nullptr, *next = list_head;
    while(next)
    {
        if(next->key == key)
            return next;
        next = next->next;
    }
    return nullptr;
}

// find element in list and get its data
template<typename T>
int clist<T>::Find(KEY_TYPE key, T& data){
    std::unique_lock<std::mutex> lock(mtx);
    _list<T>* ret = Find(key);
    if(ret)
    {   
        data = ret->data;
        return true;
    }
    else
    {
        //std::cout <<" key is no exist!:" << key << std::endl;
    }
    return false;
}

template<typename T>
void clist<T>::print(std::string title)
{
    std::cout << title << ":limit_size:" << list_max_size << "," << "size:" << list_cur_size <<std::endl;
    _list<T>* next = list_head;
    while(next)
    {
        std::cout << "element:" << next->key << "," << next->data <<std::endl;
        next = next->next;
    }
}

// 二、树存储


}


// 使用ltest
using namespace ltest;



//gtest测试框架
#include <gtest/gtest.h>


// 1、接口测试
TEST(CListTest, EmptyList) {
    clist<int> list;
    EXPECT_EQ(list.GetSize(), 0);

    list.Clear();
    EXPECT_EQ(list.GetSize(), 0);
}

// 2、添加删除测试
TEST(CListTest, AddAndDelete) {
    clist<int> list;
    int data = 42;
    int key = 1;

    EXPECT_TRUE(list.Add(key, data));
    EXPECT_EQ(list.GetSize(), 1);

    EXPECT_FALSE(list.Add(key, data)); // Adding the same key again should fail

    EXPECT_TRUE(list.Delete(key));
    EXPECT_EQ(list.GetSize(), 0);

    EXPECT_FALSE(list.Delete(key)); // Deleting a non-existent key should fail
}

// 3、添加、查找测试
TEST(CListTest, Find) {
    clist<std::string> list;
    std::string data1 = "42";
    std::string data2 = "100";
    int key1 = 1;
    int key2 = 2;

    EXPECT_TRUE(list.Add(key1, data1));
    EXPECT_TRUE(list.Add(key2, data2));

    std::string  foundData1;
    std::string  foundData2;

    EXPECT_TRUE(list.Find(key1, foundData1));
    EXPECT_TRUE(list.Find(key2, foundData2));

    EXPECT_EQ(foundData1, data1);
    EXPECT_EQ(foundData2, data2);
}

//多线程测试
TEST(CListTest, MultipleThreads) {
    clist<std::string> list;
    const int num_threads = 10;
    const int num_adds = 100;

    std::vector<std::thread> threads;

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

    // 验证列表大小是否正确
    EXPECT_EQ(list.GetSize(), num_adds);

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

    // 验证列表是否为空
    EXPECT_EQ(list.GetSize(), 0);
}

// 内容测试
TEST(CListTest, content) 
{
    clist<std::string> list(10, true);
    const int num_adds = 12;
    for (int i = 0; i < num_adds; i++) {
        std::string data = "String_" + std::to_string(i);
        list.Add(i, data);
    }

    list.print();

    // 验证列表大小是否正确
    EXPECT_EQ(list.GetSize(), 10);

    list.Clear();
    list.print("clear");
    EXPECT_EQ(list.GetSize(), 0);

    for (int i = 0; i < num_adds; i++) {
        std::string data = "String_" + std::to_string(i);
        list.Add(i, data);
    }
    list.print("add");

    EXPECT_EQ(list.GetSize(), 10);

    for (int i = 0; i < num_adds; i++) {
        if(i%2){
            list.Delete(i);
        }
        std::string data = "String_" + std::to_string(i);
        list.Add(i+8, data);
    }

    list.print("change");
}

// Add more test cases as needed

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}