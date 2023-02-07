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

// 自力AC

class Solution {
    unordered_map<TreeNode*, int> memo;
    int search(TreeNode* vnode) {
        if (memo.find(vnode) != memo.end()) return memo[vnode];
        if (vnode == nullptr) return (memo[vnode] = 0);
        else {
            int val1 = vnode->val, val2 = search(vnode->left) + search(vnode->right);
            if (vnode->left != nullptr) val1 += search(vnode->left->left) + search(vnode->left->right);
            if (vnode->right != nullptr) val1 += search(vnode->right->left) + search(vnode->right->right);
            return (memo[vnode] = max(val1, val2));
        }
    }
public:
    int rob(TreeNode* root) {
        return search(root);
    }
};
