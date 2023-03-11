// 学習1回目,解説AC3

#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    TreeNode* pnode;
    bool traverse(TreeNode* vnode) {
        if (vnode == nullptr) return true;
        if (!traverse(vnode->left) || (pnode!=nullptr && vnode->val<=pnode->val)) return false;
        pnode = vnode;
        return traverse(vnode->right);
    }
public:
    bool isValidBST(TreeNode* root) {
        pnode = nullptr;
        return traverse(root);
    }
};
