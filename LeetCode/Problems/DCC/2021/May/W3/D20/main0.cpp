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
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        unordered_map<TreeNode*, int> dist;
        queue<TreeNode*> que;
        if (root != nullptr) {
            res.push_back(vector<int>({}));
            res[0].push_back(root->val);
            dist[root] = 0;
            que.push(root);
        }
        while (!que.empty()) {
            auto vnode = que.front(); que.pop();
            int di = dist[vnode], ndi = di + 1;
            if (vnode->left != nullptr) {
                if (ndi >= (int)(res.size())) res.push_back(vector<int>({}));
                res[ndi].push_back(vnode->left->val);
                dist[vnode->left] = ndi;
                que.push(vnode->left);
            }
            if (vnode->right != nullptr) {
                if (ndi >= (int)(res.size())) res.push_back(vector<int>({}));
                res[ndi].push_back(vnode->right->val);
                dist[vnode->right] = ndi;
                que.push(vnode->right);
            }
        }
        return res;
    }
};
