// 解説AC1(BFS解)

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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        queue<TreeNode*> que;
        if (root != nullptr) que.push(root);
        while (!que.empty()) {
            int n = que.size();
            for (int i=0; i<n; ++i) {
                TreeNode* vnode = que.front(); que.pop();
                if (i == n-1) res.push_back(vnode->val);
                if (vnode->left != nullptr) que.push(vnode->left);
                if (vnode->right != nullptr) que.push(vnode->right);
            }
        }
        return res;
    }
};
