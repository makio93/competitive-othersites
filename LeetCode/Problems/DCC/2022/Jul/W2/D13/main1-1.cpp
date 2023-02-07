// 解説AC1

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        auto dfs = [&](auto dfs, TreeNode* vnode, size_t dep=0) -> void {
            if (!vnode) return;
            if (res.size() == dep) res.push_back({});
            res[dep].push_back(vnode->val);
            dfs(dfs, vnode->left, dep+1);
            dfs(dfs, vnode->right, dep+1);
        };
        dfs(dfs, root);
        return res;
    }
};
