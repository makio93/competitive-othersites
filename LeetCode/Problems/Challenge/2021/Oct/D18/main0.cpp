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

// 自力AC

class Solution {
    vector<unordered_map<int, unordered_set<TreeNode*>>> memos;
    void dfs(vector<int>& xy, TreeNode* vnode, TreeNode* pnode=nullptr, int d=0) {
        if (vnode == nullptr) return;
        int vid = -1;
        for (int i=0; i<2; ++i) if (vnode->val == xy[i]) vid = i;
        if (vid != -1) memos[vid][d].insert(pnode);
        dfs(xy, vnode->left, vnode, d+1); dfs(xy, vnode->right, vnode, d+1);
    }
public:
    bool isCousins(TreeNode* root, int x, int y) {
        memos.assign(2, unordered_map<int, unordered_set<TreeNode*>>());
        vector<int> xy({x, y});
        dfs(xy, root);
        if (!memos[0].empty() && !memos[1].empty()) for (auto pi : memos[0]) if (memos[1].find(pi.first) != memos[1].end()) {
            for (auto pit : pi.second) if (memos[1][pi.first].find(pit) == memos[1][pi.first].end()) return true;
        }
        return false;
    }
};
