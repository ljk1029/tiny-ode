#include <iostream>
#include <thread>
#include <mutex>
#include <utility>

/**
 * 1、平衡二叉树
*/
namespace tree
{
// 平衡二叉树节点类模板
template <typename T>
class AVLNode {
public:
    T data;                     // 节点值
    int height;                 // 节点高度
    AVLNode<T>* left;           // 左子节点
    AVLNode<T>* right;          // 右子节点

    // 构造函数
    AVLNode(T value) {
        data = value;
        height = 1;
        left = nullptr;
        right = nullptr;
    }
};

// 平衡二叉树操作类模板
template <typename T>
class AVLTree {
public:
    AVLNode<T>* root;

    // 构造函数
    AVLTree() {
        root = nullptr;
    }

    // 计算节点高度
    int getHeight(AVLNode<T>* node) {
        if (node == nullptr)
            return 0;
        return node->height;
    }

    // 计算节点平衡因子
    int getBalanceFactor(AVLNode<T>* node) {
        if (node == nullptr)
            return 0;
        return getHeight(node->left) - getHeight(node->right);
    }

    // 更新节点高度
    void updateHeight(AVLNode<T>* node) {
        if (node == nullptr)
            return;
        int leftHeight = getHeight(node->left);
        int rightHeight = getHeight(node->right);
        node->height = std::max(leftHeight, rightHeight) + 1;
    }

    // 右旋操作
    AVLNode<T>* rightRotate(AVLNode<T>* node) {
        AVLNode<T>* leftChild = node->left;
        node->left = leftChild->right;
        leftChild->right = node;
        updateHeight(node);
        updateHeight(leftChild);
        return leftChild;
    }

    // 左旋操作
    AVLNode<T>* leftRotate(AVLNode<T>* node) {
        AVLNode<T>* rightChild = node->right;
        node->right = rightChild->left;
        rightChild->left = node;
        updateHeight(node);
        updateHeight(rightChild);
        return rightChild;
    }

    // 插入节点
    AVLNode<T>* insertNode(AVLNode<T>* node, T value) {
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
    void inorderTraversal(AVLNode<T>* node) {
        if (node == nullptr)
            return;

        inorderTraversal(node->left);
        std::cout << node->data << " ";
        inorderTraversal(node->right);
    }

    // 寻找最小节点
    AVLNode<T>* findMinNode(AVLNode<T>* node) {
        if (node == nullptr)
            return nullptr;
        if (node->left == nullptr)
            return node;
        return findMinNode(node->left);
    }

    // 删除节点
    AVLNode<T>* deleteNode(AVLNode<T>* node, T value) {
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
                AVLNode<T>* rightChild = node->right;
                delete node;
                return rightChild;
            } else if (node->right == nullptr) {
                // 只有左子节点，用左子节点替换被删除节点
                AVLNode<T>* leftChild = node->left;
                delete node;
                return leftChild;
            } else {
                // 有两个子节点，找到右子树中最小节点，用最小节点的值替换被删除节点的值，并删除最小节点
                AVLNode<T>* minNode = findMinNode(node->right);
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
    AVLNode<T>* rightBalance(AVLNode<T>* node) {
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
    AVLNode<T>* leftBalance(AVLNode<T>* node) {
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

} 


// 树测试
void test_tree_insrt() {
    tree::AVLTree<int> avlTree;
    
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

void test_tree_delete() {
    tree::AVLTree<std::string> avlTree;
   
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

// 测试函数入口
int main(int argc, char *argv[]) {
    test_tree_insrt();
    test_tree_delete();
    return 0;
}