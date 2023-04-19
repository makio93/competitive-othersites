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
    int dfs(TreeNode* node, bool left, int val=0) {
        if (node == nullptr) return val-1;
        if (left) return max(dfs(node->left, !left, val+1), dfs(node->right, left, 1));
        else return max(dfs(node->left, left, 1), dfs(node->right, !left, val+1));
    }
public:
    int longestZigZag(TreeNode* root) {
        return max(dfs(root, true), dfs(root, false));
    }
};
