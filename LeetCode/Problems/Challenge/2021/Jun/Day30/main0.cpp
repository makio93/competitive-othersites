#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 自力AC

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return nullptr;
        else if (root==p || root==q) return root;
        else {
            auto lres = lowestCommonAncestor(root->left, p, q), rres = lowestCommonAncestor(root->right, p, q);
            if (lres!=nullptr && rres!=nullptr) return root;
            else if (lres != nullptr) return lres;
            else if (rres != nullptr) return rres;
            else return nullptr;
        }
    }
};
