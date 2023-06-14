// 解説AC3

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

const int INF = (int)(1e9);
class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        int pval = -INF, res = INF;
        function<void(TreeNode*)> dfs = [&](TreeNode* vnode) {
            if (vnode->left) dfs(vnode->left);
            if (pval != -INF) res = min(res, vnode->val-pval);
            pval = vnode->val;
            if (vnode->right) dfs(vnode->right);
        };
        dfs(root);
        return res;
    }
};
