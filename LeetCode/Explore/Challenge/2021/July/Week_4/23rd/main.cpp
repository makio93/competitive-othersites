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

// 自力解答,AC

class Solution {
    int dfs(TreeNode* pnode) {
        if (pnode == nullptr) return 0;
        int lres = dfs(pnode->left), rres = dfs(pnode->right);
        if (lres == 0) pnode->left = nullptr;
        if (rres == 0) pnode->right = nullptr;
        return (lres + rres + (pnode->val==1 ? 1 : 0));
    }
public:
    TreeNode* pruneTree(TreeNode* root) {
        int res = dfs(root);
        if (res == 0) return nullptr;
        else return root;
    }
};
