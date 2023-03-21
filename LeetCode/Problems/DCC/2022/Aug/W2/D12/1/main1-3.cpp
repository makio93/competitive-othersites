// 解説AC3

#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if ((long long)(q->val-root->val)*(p->val-root->val) < 1) return root;
        return lowestCommonAncestor(p->val < root->val ? root->left : root->right, p, q);
    }
};
