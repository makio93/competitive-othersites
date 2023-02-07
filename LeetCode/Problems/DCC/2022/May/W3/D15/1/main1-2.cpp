// 学習1回目,解説AC2

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
    int deepestLeavesSum(TreeNode* root) {
        int res = 0;
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            int qlen = que.size();
            res = 0;
            while (qlen > 0) {
                auto node = que.front(); que.pop();
                res += node->val;
                if (node->left != nullptr) que.push(node->left);
                if (node->right != nullptr) que.push(node->right);
                --qlen;
            }
        }
        return res;
    }
};
