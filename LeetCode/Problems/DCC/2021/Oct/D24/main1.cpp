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

// 解説AC

class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == nullptr) return 0;
        int height = 1;
        auto lptr = root->left, rptr = root->right;
        while (rptr != nullptr) {
            lptr = lptr->left;
            rptr = rptr->right;
            ++height;
        }
        if (lptr == nullptr) return (1<<height) - 1;
        else return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
