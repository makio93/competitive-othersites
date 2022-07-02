// 自力AC

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
public:
    int deepestLeavesSum(TreeNode* root) {
        int res = 0, md = -1;
        auto dfs = [&](auto dfs, TreeNode* vnode, int d=0) -> void {
            if (vnode == nullptr) return;
            if (d == md) res += vnode->val;
            if (d > md) {
                res = vnode->val;
                md = d;
            }
            dfs(dfs, vnode->left, d+1);
            dfs(dfs, vnode->right, d+1);
        };
        dfs(dfs, root);
        return res;
    }
};
