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

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> que;
        if (root) que.push(root);
        while (!que.empty()) {
            int n = que.size();
            res.push_back({});
            while (n--) {
                auto vnode = que.front(); que.pop();
                res.back().push_back(vnode->val);
                if (vnode->left) que.push(vnode->left);
                if (vnode->right) que.push(vnode->right);
            }
        }
        return res;
    }
};
