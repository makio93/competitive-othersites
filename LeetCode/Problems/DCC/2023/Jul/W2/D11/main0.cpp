// 自力AC

#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<int, vector<int>> g;
        function<void(TreeNode*)> dfs = [&](TreeNode* vnode) {
            if (vnode->left) {
                g[vnode->val].push_back(vnode->left->val);
                g[vnode->left->val].push_back(vnode->val);
                dfs(vnode->left);
            }
            if (vnode->right) {
                g[vnode->val].push_back(vnode->right->val);
                g[vnode->right->val].push_back(vnode->val);
                dfs(vnode->right);
            }
        };
        dfs(root);
        queue<int> que;
        unordered_map<int, int> dists;
        que.push(target->val);
        dists[target->val] = 0;
        while (!que.empty()) {
            int vi = que.front(); que.pop();
            int di = dists[vi], ndi = di + 1;
            for (const int& ti : g[vi]) if (dists.find(ti) == dists.end()) {
                dists[ti] = ndi;
                que.push(ti);
            }
        }
        vector<int> res;
        for (const auto& [vi, di] : dists) if (di == k) res.push_back(vi);
        return res;
    }
};
