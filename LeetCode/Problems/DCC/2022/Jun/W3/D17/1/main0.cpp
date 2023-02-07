// 学習1回目,自力AC

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
        int res = 0;
        auto dfs = [&](auto dfs, TreeNode* node, TreeNode* pnode=nullptr) -> void {
            if (node == nullptr) return;
            dfs(dfs, node->left, node);
            dfs(dfs, node->right, node);
            bool cam = false;
            if (node->left!=nullptr && seen.find(node->left)==seen.end()) {
                seen.insert(node->left);
                cam = true;
            }
            if (node->right!=nullptr && seen.find(node->right)==seen.end()) {
                seen.insert(node->right);
                cam = true;
            }
            if (cam) {
                ++res;
                seen.insert(node);
                if (pnode != nullptr) seen.insert(pnode);
            }
        };
        dfs(dfs, root);
        if (seen.find(root) == seen.end()) ++res;
        return res;
    }
};
