/**
给定两个整数数组 preorder 和 inorder ，其中 preorder 是二叉树的先序遍历， inorder
是同一棵树的中序遍历，请构造二叉树并返回其根节点。



示例 1:


输入: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
输出: [3,9,20,null,null,15,7]
示例 2:

输入: preorder = [-1], inorder = [-1]
输出: [-1]
*/
#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include "../common.h"

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    // 用前序遍历和中序遍历创建二叉树
    TreeNode *treePreToInHelper(std::vector<int> &preorder, int preStart, int preEnd, std::vector<int> &inorder,
                                int inStart, int inEnd) {
        if (preStart > preEnd || inStart > inEnd)
            return nullptr;
        TreeNode *root = new TreeNode(preorder[preStart]);
        int rootIndex;
        for (int i = inStart; i <= inEnd; ++i) {
            if (inorder[i] == root->val) {
                rootIndex = i;
                break;
            }
        }
        int leftTreeSize = rootIndex - inStart;
        root->left =
            treePreToInHelper(preorder, preStart + 1, preStart + leftTreeSize, inorder, inStart, rootIndex - 1);
        root->right = treePreToInHelper(preorder, preStart + leftTreeSize + 1, preEnd, inorder, rootIndex + 1, inEnd);
        return root;
    }

    TreeNode *treePreToIn(std::vector<int> &preorder, std::vector<int> &inorder) {
        return treePreToInHelper(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }

    // 用中序遍历和后序遍历创建二叉树
    TreeNode *treeInToPostHelper(std::vector<int> &inorder, int inStart, int inEnd, std::vector<int> &postorder,
                                 int postStart, int postEnd) {
        if (inStart > inEnd || postStart > postEnd)
            return nullptr;
        TreeNode *root = new TreeNode(postorder[postEnd]);
        int rootIndex;
        for (int i = inStart; i <= inEnd; ++i) {
            if (inorder[i] == root->val) {
                rootIndex = i;
                break;
            }
        }
        int leftTreeSize = rootIndex - inStart;
        root->left =
            treeInToPostHelper(inorder, inStart, rootIndex - 1, postorder, postStart, postStart + leftTreeSize - 1);
        root->right =
            treeInToPostHelper(inorder, rootIndex + 1, inEnd, postorder, postStart + leftTreeSize, postEnd - 1);
        return root;
    }

    TreeNode *treeInToPost(std::vector<int> &inorder, std::vector<int> &postorder) {
        return treeInToPostHelper(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }

    // 用前序遍历和后序遍历创建二叉树
    TreeNode *treePreToPostHelper(std::vector<int> &preorder, int preStart, int preEnd, std::vector<int> &postorder,
                                  int postStart, int postEnd) {
        if (preStart > preEnd || postStart > postEnd)
            return nullptr;
        TreeNode *root = new TreeNode(preorder[preStart]);
        if (preStart == preEnd)
            return root;
        int leftRootValue = preorder[preStart + 1];
        int leftTreeSize = 0;
        while (postorder[postStart + leftTreeSize] != leftRootValue)
            leftTreeSize++;
        root->left = treePreToPostHelper(preorder, preStart + 1, preStart + leftTreeSize + 1, postorder, postStart,
                                         postStart + leftTreeSize);
        root->right = treePreToPostHelper(preorder, preStart + leftTreeSize + 2, preEnd, postorder,
                                          postStart + leftTreeSize + 1, postEnd - 1);
        return root;
    }

    TreeNode *treePreToPost(std::vector<int> &preorder, std::vector<int> &postorder) {
        return treePreToPostHelper(preorder, 0, preorder.size() - 1, postorder, 0, postorder.size() - 1);
    }

public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if (!preorder.size()) {
            return nullptr;
        }
        TreeNode *root = new TreeNode(preorder[0]);
        stack<TreeNode *> stk;
        stk.push(root);
        int inorderIndex = 0;
        for (int i = 1; i < preorder.size(); ++i) {
            int preorderVal = preorder[i];
            TreeNode *node = stk.top();
            if (node->val != inorder[inorderIndex]) {
                node->left = new TreeNode(preorderVal);
                stk.push(node->left);
            } else {
                while (!stk.empty() && stk.top()->val == inorder[inorderIndex]) {
                    node = stk.top();
                    stk.pop();
                    ++inorderIndex;
                }
                node->right = new TreeNode(preorderVal);
                stk.push(node->right);
            }
        }
        return root;
    }
};

void print_Tree(TreeNode *root) {
    if (!root) {
        cout << "Empty tree" << endl;
        return;
    }

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            TreeNode *curr = q.front();
            q.pop();
            if (curr) {
                cout << curr->val << " ";
                q.push(curr->left);
                q.push(curr->right);
            } else {
                cout << "null ";
            }
        }
        cout << endl;
    }
}

int main() {
    Solution sol;
    vector<int> preorder = {3, 9, 20, 15, 7}, inorder = {9, 3, 15, 20, 7};
    TreeNode *result1 = sol.buildTree(preorder, inorder);
    print_Tree(result1);
    return 0;
}
