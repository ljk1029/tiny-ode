#ifndef _TOOL_DATA_H__
#define _TOOL_DATA_H__
#include <iostream>
#include <mutex>
#include <thread>
#include <utility>

namespace data_tool {
/**
 * 1、平衡二叉树
 */
namespace tree {
// 平衡二叉树节点类模板
template <typename T> class AVLNode {
public:
    T data;            // 节点值
    int height;        // 节点高度
    AVLNode<T> *left;  // 左子节点
    AVLNode<T> *right; // 右子节点

    // 构造函数
    AVLNode(T value) {
        data = value;
        height = 1;
        left = nullptr;
        right = nullptr;
    }
};

// 平衡二叉树操作类模板
template <typename T> class AVLTree {
public:
    AVLNode<T> *root;

    // 构造函数
    AVLTree() { root = nullptr; }

    // 计算节点高度
    int getHeight(AVLNode<T> *node) {
        if (node == nullptr)
            return 0;
        return node->height;
    }

    // 计算节点平衡因子
    int getBalanceFactor(AVLNode<T> *node) {
        if (node == nullptr)
            return 0;
        return getHeight(node->left) - getHeight(node->right);
    }

    // 更新节点高度
    void updateHeight(AVLNode<T> *node) {
        if (node == nullptr)
            return;
        int leftHeight = getHeight(node->left);
        int rightHeight = getHeight(node->right);
        node->height = std::max(leftHeight, rightHeight) + 1;
    }

    // 右旋操作
    AVLNode<T> *rightRotate(AVLNode<T> *node) {
        AVLNode<T> *leftChild = node->left;
        node->left = leftChild->right;
        leftChild->right = node;
        updateHeight(node);
        updateHeight(leftChild);
        return leftChild;
    }

    // 左旋操作
    AVLNode<T> *leftRotate(AVLNode<T> *node) {
        AVLNode<T> *rightChild = node->right;
        node->right = rightChild->left;
        rightChild->left = node;
        updateHeight(node);
        updateHeight(rightChild);
        return rightChild;
    }

    // 插入节点
    AVLNode<T> *insertNode(AVLNode<T> *node, T value) {
        if (node == nullptr)
            return new AVLNode<T>(value);

        if (value < node->data) {
            node->left = insertNode(node->left, value);
            updateHeight(node);

            node = leftBalance(node);
        } else if (value > node->data) {
            node->right = insertNode(node->right, value);
            updateHeight(node);

            node = rightBalance(node);
        }

        return node;
    }

    // 中序遍历平衡二叉树
    void inorderTraversal(AVLNode<T> *node) {
        if (node == nullptr)
            return;

        inorderTraversal(node->left);
        std::cout << node->data << " ";
        inorderTraversal(node->right);
    }

    // 寻找最小节点
    AVLNode<T> *findMinNode(AVLNode<T> *node) {
        if (node == nullptr)
            return nullptr;
        if (node->left == nullptr)
            return node;
        return findMinNode(node->left);
    }

    // 删除节点
    AVLNode<T> *deleteNode(AVLNode<T> *node, T value) {
        if (node == nullptr)
            return nullptr;

        if (value < node->data) {
            node->left = deleteNode(node->left, value);
            updateHeight(node);

            node = rightBalance(node);
        } else if (value > node->data) {
            node->right = deleteNode(node->right, value);
            updateHeight(node);

            node = leftBalance(node);
        } else {
            if (node->left == nullptr && node->right == nullptr) {
                // 叶节点，直接删除
                delete node;
                return nullptr;
            } else if (node->left == nullptr) {
                // 只有右子节点，用右子节点替换被删除节点
                AVLNode<T> *rightChild = node->right;
                delete node;
                return rightChild;
            } else if (node->right == nullptr) {
                // 只有左子节点，用左子节点替换被删除节点
                AVLNode<T> *leftChild = node->left;
                delete node;
                return leftChild;
            } else {
                // 有两个子节点，找到右子树中最小节点，用最小节点的值替换被删除节点的值，并删除最小节点
                AVLNode<T> *minNode = findMinNode(node->right);
                node->data = minNode->data;
                node->right = deleteNode(node->right, minNode->data);
                updateHeight(node);

                node = leftBalance(node);
                return node;
            }
        }

        return node;
    }

private:
    // 右平衡
    AVLNode<T> *rightBalance(AVLNode<T> *node) {
        int balanceFactor = getBalanceFactor(node);
        if (balanceFactor == -2) {
            if (getBalanceFactor(node->right) == -1) {
                // RR情况，进行左旋操作
                node = leftRotate(node);
            } else if (getBalanceFactor(node->right) == 1) {
                // RL情况，先进行右旋操作，再进行左旋操作
                node->right = rightRotate(node->right);
                node = leftRotate(node);
            }
        }
        return node;
    }

    // 左平衡
    AVLNode<T> *leftBalance(AVLNode<T> *node) {
        int balanceFactor = getBalanceFactor(node);
        if (balanceFactor == 2) {
            if (getBalanceFactor(node->left) == 1) {
                // LL情况，进行右旋操作
                node = rightRotate(node);
            } else if (getBalanceFactor(node->left) == -1) {
                // LR情况，先进行左旋操作，再进行右旋操作
                node->left = leftRotate(node->left);
                node = rightRotate(node);
            }
        }
        return node;
    }
};

} // namespace tree

/**
 * 2、链表存储 key+data
 */
namespace list {
// 锁
std::mutex mtx;
using KEY_TYPE = long;

template <typename T> struct Node {
    struct Node *prev; // 向前指针
    struct Node *next; // 向后指针
    KEY_TYPE key;      // 键值
    T data;            // 数值
};

template <typename T> class CustomLinkedList {
public:
    explicit CustomLinkedList(int max_size = 512, bool log = false)
        : list_head{nullptr}, list_tail{nullptr}, list_cur_size{0} {
        list_max_size = max_size;
        log_switch = log;
    }
    ~CustomLinkedList() { Clear(); }

    int GetSize();
    int Clear();
    int Add(KEY_TYPE key, T data);
    int Delete(KEY_TYPE key);

    int Find(KEY_TYPE key, T &data);

    // 测试环境下使用，这个未加锁
    void print(std::string title = "");

private:
    Node<T> *Find(KEY_TYPE key); // 类内部使用，未加锁
    template <typename... Args> void PrintInfo(const Args &... args) {
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
template <typename T> int CustomLinkedList<T>::GetSize() { return list_cur_size; }

// clear all elements
template <typename T> int CustomLinkedList<T>::Clear() {
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

// add element to list
template <typename T> int CustomLinkedList<T>::Add(KEY_TYPE key, T data) {
    int ret = false;
    std::unique_lock<std::mutex> lock(mtx);
    if (list_cur_size >= list_max_size) {
        PrintInfo("Add failed list is full!:");
        return ret;
    }

    if (Find(key) == nullptr) {
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
        PrintInfo("Add failed key is exist!:", key, data);
    }
    return ret;
}

// delete element from list
template <typename T> int CustomLinkedList<T>::Delete(KEY_TYPE key) {
    int ret = false;
    std::unique_lock<std::mutex> lock(mtx);
    Node<T> *temp = Find(key);
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
        delete temp;
        list_cur_size--;
        ret = true;
    } else {
        PrintInfo("key no exsit!:", key);
    }
    return ret;
}

// find element in list
template <typename T> Node<T> *CustomLinkedList<T>::Find(KEY_TYPE key) {
    Node<T> *ret = nullptr, *next = list_head;
    while (next) {
        if (next->key == key)
            return next;
        next = next->next;
    }
    return nullptr;
}

// find element in list and get its data
template <typename T> int CustomLinkedList<T>::Find(KEY_TYPE key, T &data) {
    std::unique_lock<std::mutex> lock(mtx);
    Node<T> *ret = Find(key);
    if (ret) {
        data = ret->data;
        return true;
    } else {
        PrintInfo(" key is no exist!:", key);
    }
    return false;
}

template <typename T> void CustomLinkedList<T>::print(std::string title) {
    std::cout << title << ":limit_size:" << list_max_size << ","
              << "size:" << list_cur_size << std::endl;
    Node<T> *next = list_head;
    while (next) {
        std::cout << "element:" << next->key << "," << next->data << std::endl;
        next = next->next;
    }
}

} // namespace list

} // namespace data_tool

#endif