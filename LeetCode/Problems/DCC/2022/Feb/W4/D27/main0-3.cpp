// 自力AC

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
        queue<pair<TreeNode*, ll>> que;
        int res = 0;
        que.emplace(root, 0);
        while (!que.empty()) {
            int slen = que.size();
            ll li = (ll)(1e15), ri = -1, sub = que.front().second;
            for (int i=0; i<slen; ++i) {
                auto pi = que.front(); que.pop();
                auto vnode = pi.first;
                ll rval = pi.second;
                li = min(li, rval), ri = max(ri, rval);
                if (vnode->left != nullptr) que.emplace(vnode->left, (rval-sub)*2);
                if (vnode->right != nullptr) que.emplace(vnode->right, (rval-sub)*2+1);
            }
            res = max(res, (int)(ri-li+1));
        }
        return res;
    }
};
