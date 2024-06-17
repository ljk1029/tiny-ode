/**
给你一个二叉树的根节点 root ， 检查它是否轴对称。



示例 1：


输入：root = [1,2,2,3,4,4,3]
输出：true
示例 2：


输入：root = [1,2,2,null,3,null,3]
输出：false

*/
#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
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
public:
    bool check(TreeNode *p, TreeNode *q) {
        if (!p && !q)
            return true;
        if (!p || !q)
            return false;
        return p->val == q->val && check(p->left, q->right) && check(p->right, q->left);
    }

    bool isSymmetric(TreeNode *root) { return check(root, root); }

    bool _check(TreeNode *u, TreeNode *v) {
        queue<TreeNode *> q;
        q.push(u);
        q.push(v);
        while (!q.empty()) {
            u = q.front();
            q.pop();
            v = q.front();
            q.pop();
            if (!u && !v)
                continue;
            if ((!u || !v) || (u->val != v->val))
                return false;

            q.push(u->left);
            q.push(v->right);

            q.push(u->right);
            q.push(v->left);
        }
        return true;
    }

    bool _isSymmetric(TreeNode *root) { return _check(root, root); }
};

/*
// 用前序遍历和中序遍历创建二叉树
TreeNode* buildTreePreIn(std::vector<int>& preorder, std::vector<int>& inorder) {
    return buildTreePreInHelper(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
}

TreeNode* buildTreePreInHelper(std::vector<int>& preorder, int preStart, int preEnd,
                               std::vector<int>& inorder, int inStart, int inEnd) {
    if (preStart > preEnd || inStart > inEnd) return nullptr;
    TreeNode* root = new TreeNode(preorder[preStart]);
    int rootIndex;
    for (int i = inStart; i <= inEnd; ++i) {
        if (inorder[i] == root->val) {
            rootIndex = i;
            break;
        }
    }
    int leftTreeSize = rootIndex - inStart;
    root->left = buildTreePreInHelper(preorder, preStart + 1, preStart + leftTreeSize,
                                      inorder, inStart, rootIndex - 1);
    root->right = buildTreePreInHelper(preorder, preStart + leftTreeSize + 1, preEnd,
                                       inorder, rootIndex + 1, inEnd);
    return root;
}

// 用中序遍历和后序遍历创建二叉树
TreeNode* buildTreeInPost(std::vector<int>& inorder, std::vector<int>& postorder) {
    return buildTreeInPostHelper(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
}

TreeNode* buildTreeInPostHelper(std::vector<int>& inorder, int inStart, int inEnd,
                                std::vector<int>& postorder, int postStart, int postEnd) {
    if (inStart > inEnd || postStart > postEnd) return nullptr;
    TreeNode* root = new TreeNode(postorder[postEnd]);
    int rootIndex;
    for (int i = inStart; i <= inEnd; ++i) {
        if (inorder[i] == root->val) {
            rootIndex = i;
            break;
        }
    }
    int leftTreeSize = rootIndex - inStart;
    root->left = buildTreeInPostHelper(inorder, inStart, rootIndex - 1,
                                       postorder, postStart, postStart + leftTreeSize - 1);
    root->right = buildTreeInPostHelper(inorder, rootIndex + 1, inEnd,
                                        postorder, postStart + leftTreeSize, postEnd - 1);
    return root;
}

// 用前序遍历和后序遍历创建二叉树
TreeNode* buildTreePrePost(std::vector<int>& preorder, std::vector<int>& postorder) {
    return buildTreePrePostHelper(preorder, 0, preorder.size() - 1, postorder, 0, postorder.size() - 1);
}

TreeNode* buildTreePrePostHelper(std::vector<int>& preorder, int preStart, int preEnd,
                                 std::vector<int>& postorder, int postStart, int postEnd) {
    if (preStart > preEnd || postStart > postEnd) return nullptr;
    TreeNode* root = new TreeNode(preorder[preStart]);
    if (preStart == preEnd) return root;
    int leftRootValue = preorder[preStart + 1];
    int leftTreeSize = 0;
    while (postorder[postStart + leftTreeSize] != leftRootValue)
        leftTreeSize++;
    root->left = buildTreePrePostHelper(preorder, preStart + 1, preStart + leftTreeSize + 1,
                                        postorder, postStart, postStart + leftTreeSize);
    root->right = buildTreePrePostHelper(preorder, preStart + leftTreeSize + 2, preEnd,
                                         postorder, postStart + leftTreeSize + 1, postEnd - 1);
    return root;
}
*/

int main() {
    Solution sol;
    TreeNode *right = new TreeNode(3);
    TreeNode *left = new TreeNode(4);
    TreeNode *L_root = new TreeNode(2, left, right);
    right = new TreeNode(4);
    left = new TreeNode(3);
    TreeNode *r_root = new TreeNode(2, left, right);
    TreeNode *root = new TreeNode(1, L_root, r_root);
    std::cout << sol.isSymmetric(root);

    return 0;
}
