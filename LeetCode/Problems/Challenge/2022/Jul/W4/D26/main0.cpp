// 自力AC

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
        auto dfs = [&](auto dfs, TreeNode* rnode) -> int {
            if (rnode == NULL) return 0;
            if (rnode->val==p->val || rnode->val==q->val) {
                if (dfs(dfs,rnode->left)==1 || dfs(dfs,rnode->right)==1) {
                    res = rnode;
                    return 2;
                }
                else return 1;
            }
            else {
                int lval = dfs(dfs, rnode->left);
                if (lval == 2) return 2;
                int rval = dfs(dfs, rnode->right);
                if (lval==1 && rval==1) {
                    res = rnode;
                    return 2;
                }
                if (rval == 2) return 2;
                return lval + rval;
            }
        };
        dfs(dfs, root);
        return res;
    }
};
