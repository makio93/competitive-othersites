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
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == nullptr) return 0;
        else {
            int res = sumOfLeftLeaves(root->right);
            if (root->left!=nullptr && root->left->left==nullptr && root->left->right==nullptr) res += root->left->val;
            else res += sumOfLeftLeaves(root->left);
            return res;
        }
    }
};
