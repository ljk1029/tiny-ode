#include <iostream>
#include <thread>
#include <mutex>
#include <utility>
#include <thread>
#include <vector>
#include <functional>


/**
 * 2、链表存储 key+data
*/
namespace list{
// 锁
std::mutex mtx;
using KEY_TYPE = long;

template<typename T>
struct Node
{
    struct Node* prev;  // 向前指针
    struct Node* next;  // 向后指针
    KEY_TYPE key;       // 键值
    T data;             // 数值
};

template<typename T>
class CustomLinkedList{
public:
    explicit CustomLinkedList(int max_size = 512, bool log = false):list_head{nullptr},list_tail{nullptr},
        list_cur_size{0} { list_max_size = max_size; log_switch = log; }
    ~CustomLinkedList(){ Clear(); }

    int GetSize();
    int Clear();
    int Add(KEY_TYPE key, T data);
    int Delete(KEY_TYPE key);
    
    int Find(KEY_TYPE key, T &data);

    // 测试环境下使用，这个未加锁
    void print(std::string title = "");
    
private:
    Node<T>* Find(KEY_TYPE key); // 类内部使用，未加锁
    template<typename... Args>
    void PrintInfo(const Args&... args) {
        if(log_switch){
            std::cout << "Info: ";
            ((std::cout << args), ...);
            std::cout << std::endl;
        }
    }

    bool log_switch;  // log 打印开关
    Node<T>* list_head;
    Node<T>* list_tail;
    int list_max_size;
    int list_cur_size;
};

// get list current size
template<typename T>
int CustomLinkedList<T>::GetSize(){
    return list_cur_size;
}

// clear all elements
template<typename T>
int CustomLinkedList<T>::Clear(){
    std::unique_lock<std::mutex> lock(mtx);
    while(list_head)
    {
        Node<T>* temp = list_head;
        list_head  = list_head->next;
        delete temp;
    }
    list_tail = nullptr;
    list_cur_size = 0;
    return true;
}

// add element to list
template<typename T>
int CustomLinkedList<T>::Add(KEY_TYPE key, T data){
    int ret = false;
    std::unique_lock<std::mutex> lock(mtx);
    if(list_cur_size >= list_max_size){
        PrintInfo("Add failed list is full!:");
        return ret;
    }

    if(Find(key) == nullptr)
    {
        Node<T>* temp = new Node<T>;
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
int CustomLinkedList<T>::Delete(KEY_TYPE key){
    int ret = false;
    std::unique_lock<std::mutex> lock(mtx);
    Node<T>* temp = Find(key) ;
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
Node<T>* CustomLinkedList<T>::Find(KEY_TYPE key){
    Node<T>* ret = nullptr, *next = list_head;
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
int CustomLinkedList<T>::Find(KEY_TYPE key, T& data){
    std::unique_lock<std::mutex> lock(mtx);
    Node<T>* ret = Find(key);
    if(ret)
    {   
        data = ret->data;
        return true;
    }
    else
    {
        PrintInfo(" key is no exist!:", key);
    }
    return false;
}

template<typename T>
void CustomLinkedList<T>::print(std::string title)
{
    std::cout << title << ":limit_size:" << list_max_size << "," << "size:" << list_cur_size <<std::endl;
    Node<T>* next = list_head;
    while(next)
    {
        std::cout << "element:" << next->key << "," << next->data <<std::endl;
        next = next->next;
    }
}

}


// 链表测试
void test_list_init() {
    list::CustomLinkedList<int> list;
    list.print("test1");
    list.Clear();
    list.print("test1");
}

void test_list_add() {
    list::CustomLinkedList<int> list;
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

void test_list_find() {
    list::CustomLinkedList<std::string> list;
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

void test_list_thread() {
    list::CustomLinkedList<std::string> list;
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

void test_list_clear() {
    list::CustomLinkedList<std::string> list(10, true);
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

using CallbackFunc = std::function<void()>;
// 测试回调
int func_print(const std::string& title, CallbackFunc callback)
{
    std::cout << "======" << "[" << title << " test]" << "=====" << std::endl;
    callback();
    std::cout << "--------[test end]--------\n\n";
    return 0;
}

// 测试函数入口
int main(int argc, char *argv[]) 
{
    func_print("test_list_init",   test_list_init);
    func_print("test_list_add",    test_list_add);
    func_print("test_list_find",   test_list_find);
    func_print("test_list_thread", test_list_thread);
    func_print("test_list_clear",  test_list_clear);
    return 0;
}