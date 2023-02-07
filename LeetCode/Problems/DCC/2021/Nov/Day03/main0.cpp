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

using ll = long long;
class Solution {
    ll calc(TreeNode* vnode, ll pval=0) {
        if (vnode == nullptr) return 0;
        ll val = pval * 10 + vnode->val;
        if (vnode->left==nullptr && vnode->right==nullptr) return val;
        return calc(vnode->left, val) + calc(vnode->right, val);
    }
public:
    int sumNumbers(TreeNode* root) {
        return (int)(calc(root));
    }
};
