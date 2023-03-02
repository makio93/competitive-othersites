// 学習1回目,解説AC1

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
        auto dfs = [&](auto dfs, TreeNode* vnode) -> bool {
            if (res!=NULL || vnode==NULL) return false;
            int bcnt = 0;
            if (vnode==p || vnode==q) ++bcnt;
            if (dfs(dfs, vnode->left)) ++bcnt;
            if (dfs(dfs, vnode->right)) ++bcnt;
            if (bcnt >= 2) {
                res = vnode;
                return false;
            }
            return bcnt >= 1;
        };
        dfs(dfs, root);
        return res;
    }
};
