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
        queue<TreeNode*> que;
        if (root != nullptr) que.push(root);
        while (!que.empty()) {
            queue<TreeNode*> nque;
            vector<int> vals;
            while (!que.empty()) {
                auto p = que.front(); que.pop();
                vals.push_back(p->val);
                if (p->left != nullptr) nque.push(p->left);
                if (p->right != nullptr) nque.push(p->right);
            }
            res.push_back(vals);
            swap(que, nque);
        }
        return res;
    }
};
