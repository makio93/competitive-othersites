// 自力,RE

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
    unordered_map<int, vector<int>> mvals;
    void dfs(TreeNode* vnode, int d=0) {
        if (vnode == nullptr) {
            mvals[d].push_back(-1);
            return;
        }
        mvals[d].push_back(1);
        dfs(vnode->left, d+1);
        dfs(vnode->right, d+1);
    }
public:
    int widthOfBinaryTree(TreeNode* root) {
        dfs(root);
        int res = 0;
        for (auto pi : mvals) {
            int li = (int)(1e9), ri = -1;
            for (int i=0; i<(int)(pi.second.size()); ++i) if (pi.second[i] > 0) {
                li = min(li, i);
                ri = max(ri, i);
            }
            if (ri != -1) res = max(res, ri-li+1);
        }
        return res;
    }
};
