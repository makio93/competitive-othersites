// 自力AC2

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
    void flatten(TreeNode* root) {
        auto ptr = root;
        while (ptr != nullptr) {
            if (ptr->left != nullptr) {
                auto rptr = ptr->left;
                while (rptr->right != nullptr) rptr = rptr->right;
                rptr->right = ptr->right;
                ptr->right = ptr->left;
                ptr->left = nullptr;
            }
            ptr = ptr->right;
        }
    }
};
