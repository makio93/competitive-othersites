// 学習1回目,解説AC2

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
    int minCameraCover(TreeNode* root) {
        unordered_set<TreeNode*> seen;
        seen.insert(nullptr);
        int res = 0;
        auto dfs = [&](auto dfs, TreeNode* node, TreeNode* pnode=nullptr) -> void {
            if (node == nullptr) return;
            dfs(dfs, node->left, node);
            dfs(dfs, node->right, node);
            if ((pnode==nullptr&&seen.find(node)==seen.end()) || 
                seen.find(node->left)==seen.end() || seen.find(node->right)==seen.end()) {
                seen.insert(node);
                seen.insert(node->left);
                seen.insert(node->right);
                seen.insert(pnode);
                ++res;
            }
        };
        dfs(dfs, root);
        return res;
    }
};
