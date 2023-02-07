// 自力WA

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
    unordered_map<int, pair<int, int>> mvals;
    void dfs(TreeNode* vnode, int d=0, int r=0) {
        if (vnode == nullptr) return;
        mvals[d].first = min(mvals[d].first, r);
        mvals[d].second = max(mvals[d].second, r);
        dfs(vnode->left, d+1, r*2);
        dfs(vnode->right, d+1, r*2+1);
    }
public:
    int widthOfBinaryTree(TreeNode* root) {
        dfs(root);
        int res = 0;
        for (auto pi : mvals) res = max(res, pi.second.second-pi.second.first+1);
        return res;
    }
};
