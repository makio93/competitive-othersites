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
    vector<vector<int>> res;
    void dfs(vector<int>& path, TreeNode* node, int rest) {
        if (node == nullptr) return;
        path.push_back(node->val);
        rest -= node->val;
        if (node->left==nullptr && node->right==nullptr && rest==0) res.push_back(path);
        dfs(path, node->left, rest);
        dfs(path, node->right, rest);
        rest += node->val;
        path.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        res = vector<vector<int>>(0);
        vector<int> path;
        dfs(path, root, targetSum);
        return res;
    }
};
