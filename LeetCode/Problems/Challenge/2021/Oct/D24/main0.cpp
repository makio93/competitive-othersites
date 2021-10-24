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
    int dfs(TreeNode* vnode, int val=1) {
        if (vnode == nullptr) return val / 2;
        else return max(dfs(vnode->right, val*2+1), dfs(vnode->left, val*2));
    }
public:
    int countNodes(TreeNode* root) {
        return dfs(root);
    }
};
