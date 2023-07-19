// 学習1回目,自力WA

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
        int res = INF;
        function<void(TreeNode*)> dfs = [&](TreeNode* vnode) {
            if (vnode->left) {
                res = min(res, abs(vnode->left->val-vnode->val));
                dfs(vnode->left);
            }
            if (vnode->right) {
                res = min(res, abs(vnode->right->val-vnode->val));
                dfs(vnode->right);
            }
        };
        dfs(root);
        return res;
    }
};
