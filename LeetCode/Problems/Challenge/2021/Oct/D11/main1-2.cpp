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

// 解説AC2,計算時間,メモリ節約

class Solution {
    int dfs(TreeNode* tnode, int& mval) {
        int lval = tnode->left == nullptr ? 0 : dfs(tnode->left, mval), 
            rval = tnode->right == nullptr ? 0 : dfs(tnode->right, mval);
        mval = max(mval, lval+rval);
        return max(lval, rval) + 1;
    };
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        dfs(root, res);
        return res;
    }
};
