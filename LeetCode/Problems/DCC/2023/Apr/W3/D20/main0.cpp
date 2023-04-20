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
        vector<ll> svals;
        ll res = 0;
        auto dfs = [&](auto& dfs, TreeNode* vnode, int dep=0, ll val=0LL) -> void {
            if (vnode == nullptr) return;
            if (svals.size() <= dep) svals.push_back(val);
            val -= svals[dep];
            res = max(res, val+1);
            dfs(dfs, vnode->left, dep+1, val*2);
            dfs(dfs, vnode->right, dep+1, val*2+1);
        };
        dfs(dfs, root);
        return (int)res;
    }
};
