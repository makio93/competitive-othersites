// 解説AC2

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
    TreeNode* phead = nullptr;
    void search(TreeNode* vnode) {
        if (vnode->right) search(vnode->right);
        if (vnode->left) search(vnode->left);
        vnode->right = phead;
        vnode->left = nullptr;
        phead = vnode;
    }
public:
    void flatten(TreeNode* root) {
        if (root) search(root);
    }
};
