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
    int sum, mdep;
    int dfs(TreeNode* root, int depth=0) {
        if (root == nullptr) return sum;
        if (root->left==nullptr && root->right==nullptr) {
            if (depth > mdep) sum = root->val, mdep = depth;
            else if (depth == mdep) sum += root->val;
        }
        dfs(root->left, depth+1);
        dfs(root->right, depth+1);
        return sum;
    }
public:
    int deepestLeavesSum(TreeNode* root) {
        sum = 0, mdep = -1;
        return dfs(root);
    }
};
