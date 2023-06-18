// 解説AC

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
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<ll, TreeNode*>> que;
        que.emplace(0, root);
        ll res = 1;
        while (!que.empty()) {
            int qlen = que.size();
            ll sub = -1;
            while (qlen > 0) {
                auto [val, vnode] = que.front(); que.pop();
                if (vnode->left != nullptr) {
                    if (sub == -1) sub = val * 2;
                    que.emplace(val*2-sub, vnode->left);
                    res = max(res, val*2-sub+1);
                }
                if (vnode->right != nullptr) {
                    if (sub == -1) sub = val * 2 + 1;
                    que.emplace(val*2+1-sub, vnode->right);
                    res = max(res, val*2+1-sub+1);
                }
                --qlen;
            }
        }
        return (int)res;
    }
};
