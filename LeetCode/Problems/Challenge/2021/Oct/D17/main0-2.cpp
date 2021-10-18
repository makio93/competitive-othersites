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

// 非自力AC

using ll = long long;
class Solution {
    map<pair<TreeNode*, ll>, int> cnts;
    int dfs(TreeNode* rnode, int add, int& targetSum) {
        if (rnode == nullptr) return 0;
        int nval = add + rnode->val;
        return (nval==targetSum ? 1 : 0) + dfs(rnode->left, nval, targetSum) + dfs(rnode->right, nval, targetSum);
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return 0;
        return dfs(root, 0, targetSum) + pathSum(root->left, targetSum) + pathSum(root->right, targetSum);
    }
};
