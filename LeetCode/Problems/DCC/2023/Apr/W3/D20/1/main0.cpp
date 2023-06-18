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

using ll = long long;
const ll LINF = (ll)(1e18);
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, ll>> que;
        ll res = 1, sub = 0;
        que.emplace(root, 0);
        while (!que.empty()) {
            int qlen = que.size();
            ll lval = LINF, rval = -1;
            while (qlen) {
                auto [vnode, val] = que.front(); que.pop();
                if (vnode->left) {
                    ll tval = (val - sub) * 2;
                    que.emplace(vnode->left, tval);
                    lval = min(lval, tval);
                    rval = max(rval, tval);
                }
                if (vnode->right) {
                    ll tval = (val - sub) * 2 + 1;
                    que.emplace(vnode->right, tval);
                    lval = min(lval, tval);
                    rval = max(rval, tval);
                }
                --qlen;
            }
            res = max(res, rval-lval+1);
            sub = lval;
        }
        return (int)(res);
    }
};
