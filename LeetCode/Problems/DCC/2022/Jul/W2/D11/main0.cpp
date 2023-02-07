// 

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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        auto dfs = [&](auto dfs, TreeNode* vnode, int dep=0) -> void {
            if (vnode == nullptr) return;
            if ((int)(res.size()) == dep) res.push_back(vnode->val);
            else res[dep] = vnode->val;
            dfs(dfs, vnode->left, dep+1);
            dfs(dfs, vnode->right, dep+1);
        };
        dfs(dfs, root);
        return res;
    }
};
