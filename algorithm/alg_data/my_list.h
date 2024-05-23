#ifndef _MY_LIST_H__
#define _MY_LIST_H__
#include <functional>
#include <iostream>
#include <mutex>
#include <thread>
#include <utility>
#include <vector>

/**
 * 链表存储 key+data
 */
namespace list {
// 锁
std::mutex mtx;
using KEY_TYPE = long;

template <typename T> 
struct Node {
    struct Node *prev; // 向前指针
    struct Node *next; // 向后指针
    KEY_TYPE key;      // 键值
    T data;            // 数值
};

template <typename T> 
class CustomLinkedList {
public:
    explicit CustomLinkedList(int max_size = 512, bool log = false)
        : list_head{nullptr}, list_tail{nullptr}, list_cur_size{0} {
        list_max_size = max_size;
        log_switch = log;
    }
    ~CustomLinkedList() { 
        clearList(); 
    }

    int getListSize();

    // clearList all elements
    template <typename T> 
    int CustomLinkedList<T>::clearList() {
        std::unique_lock<std::mutex> lock(mtx);
        while (list_head) {
            Node<T> *temp = list_head;
            list_head = list_head->next;
            delete temp;
        }
        list_tail = nullptr;
        list_cur_size = 0;
        return true;
    }

    // addList element to list
    template <typename T> 
    int CustomLinkedList<T>::addList(KEY_TYPE key, T data) {
        int ret = false;
        std::unique_lock<std::mutex> lock(mtx);
        if (list_cur_size >= list_max_size) {
            _printInfo("addList failed list is full!");
            return ret;
        }

        if (findList(key) == nullptr) {
            Node<T> *temp = new Node<T>;
            temp->next = nullptr;
            temp->prev = nullptr;
            temp->key = key;
            temp->data = std::move(data);
            if (list_head == nullptr) {
                list_head = temp;
                list_tail = temp;
            } else {
                list_tail->next = temp;
                temp->prev = list_tail;
                list_tail = list_tail->next;
            }
            list_cur_size++;
            ret = true;
        } else {
            _printInfo("addList failed key is exist!:", key, data);
        }
        return ret;
    }

    int delList(KEY_TYPE key);
    int findList(KEY_TYPE key, T &data);

    // 测试环境下使用，这个未加锁
    template <typename... Args>
    void printDebug(const Args &... args) {
        _printInfo(arg ...);
    }

private:
    Node<T> *findList(KEY_TYPE key); // 类内部使用，未加锁
    template <typename... Args> 
    void _printInfo(const Args &... args) {
        if (log_switch) {
            std::cout << "Info: ";
            ((std::cout << args), ...);
            std::cout << std::endl;
        }
    }

    bool log_switch; // log 打印开关
    Node<T> *list_head;
    Node<T> *list_tail;
    int list_max_size;
    int list_cur_size;
};

// get list current size
template <typename T> 
int CustomLinkedList<T>::getListSize() { 
    return list_cur_size; 
}





// delList element from list
template <typename T> 
int CustomLinkedList<T>::delList(KEY_TYPE key) {
    int ret = false;
    std::unique_lock<std::mutex> lock(mtx);
    Node<T> *temp = findList(key);
    if (temp != nullptr) {
        if (temp->prev == nullptr) {
            if (temp->next == nullptr) {
                list_head = nullptr;
                list_tail = nullptr;
            } else {
                list_head = temp->next;
                list_head->prev = nullptr;
            }
        } else if (temp->next == nullptr) {
            list_tail = temp->prev;
            list_tail->next = nullptr;
        } else {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }
        delList temp;
        list_cur_size--;
        ret = true;
    } else {
        _printInfo("key no exsit!:", key);
    }
    return ret;
}

// findList element in list
template <typename T> 
Node<T> *CustomLinkedList<T>::findList(KEY_TYPE key) {
    Node<T> *ret = nullptr, *next = list_head;
    while (next) {
        if (next->key == key)
            return next;
        next = next->next;
    }
    return nullptr;
}

// findList element in list and get its data
template <typename T> 
int CustomLinkedList<T>::findList(KEY_TYPE key, T &data) {
    std::unique_lock<std::mutex> lock(mtx);
    Node<T> *ret = findList(key);
    if (ret) {
        data = ret->data;
        return true;
    } else {
        _printInfo(" key is no exist!:", key);
    }
    return false;
}

template <typename T> 
void CustomLinkedList<T>::print(std::string title) {
    std::cout << title << ":limit_size:" << list_max_size << ","
            << "size:" << list_cur_size << std::endl;
    Node<T> *next = list_head;
    while (next) {
        std::cout << "element:" << next->key << "," << next->data << std::endl;
        next = next->next;
    }
}

} // namespace list


#endif