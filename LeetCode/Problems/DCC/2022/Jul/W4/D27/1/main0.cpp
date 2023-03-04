// 学習1回目,自力AC

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
    TreeNode* repair(TreeNode* root) {
        if (root == nullptr) return nullptr;
        if (root->left==nullptr && root->right==nullptr) return root;
        if (root->right == nullptr) {
            root->right = root->left;
            root->left = nullptr;
        }
        auto tail = repair(root->right);
        if (root->left != nullptr) {
            repair(root->left)->right = root->right;
            root->right = root->left;
            root->left = nullptr;
        }
        return tail;
    }
public:
    void flatten(TreeNode* root) {
        repair(root);
    }
};
