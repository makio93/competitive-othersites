// 解説AC1

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
        TreeNode *res = NULL;
        auto dfs = [&](auto dfs, TreeNode* rnode) -> bool {
            if (rnode == NULL) return false;
            int lval = dfs(dfs, rnode->left) ? 1 : 0;
            int rval = dfs(dfs, rnode->right) ? 1 : 0;
            int mval = (rnode->val==p->val || rnode->val==q->val) ? 1 : 0;
            if (lval+rval+mval == 2) res = rnode;
            return (lval+rval+mval >= 1); 
        };
        dfs(dfs, root);
        return res;
    }
};
