#include "my_tree.h"

// 树测试
void testTreeInsrt() {
    my_tree::AVLTree<int> avlTree;

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

void testTreeDelete() {
    my_tree::AVLTree<std::string> avlTree;

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
    // avlTree.root = avlTree.deleteNode(avlTree.root, "apple");
    avlTree.root = avlTree.deleteNode(avlTree.root, "fig");

    // 中序遍历
    avlTree.inorderTraversal(avlTree.root);
    std::cout << std::endl;
}

// 测试函数入口
int main(int argc, char *argv[]) {
    testTreeInsrt();
    testTreeDelete();
    return 0;
}