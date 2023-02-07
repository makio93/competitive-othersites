// 学習1回目,自力AC

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
public:
    int deepestLeavesSum(TreeNode* root) {
        int mdep = 0, res = 0;
        auto dfs = [&](auto dfs, TreeNode *vnode, int di=0) -> void {
            if (vnode->left==nullptr && vnode->right==nullptr) {
                if (di > mdep) {
                    mdep = di;
                    res = vnode->val;
                }
                else if (di == mdep) res += vnode->val;
                return;
            }
            if (vnode->left != nullptr) dfs(dfs, vnode->left, di+1);
            if (vnode->right != nullptr) dfs(dfs, vnode->right, di+1);
        };
        dfs(dfs, root);
        return res;
    }
};
