// 学習1回目,自力AC1

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
        TreeNode* res = NULL;
        auto dfs = [&](auto dfs, TreeNode* node) -> bool {
            if (node == NULL) return false;
            bool vval = (node == p) || (node == q), lval = dfs(dfs, node->left), rval = dfs(dfs, node->right);
            if ((lval&&rval) || ((lval||rval)&&vval)) {
                res = node;
                return false;
            }
            else if (lval || rval) return true;
            else return vval;
        };
        dfs(dfs, root);
        return res;
    }
};
