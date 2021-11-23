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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) return root;
        else {
            auto ptr = root, parent = (TreeNode*)nullptr;
            bool left = true;
            while (ptr!=nullptr && ptr->val!=key) {
                parent = ptr;
                if (ptr->val > key) {
                    ptr = ptr->left;
                    left = true;
                }
                else if (ptr->val < key) {
                    ptr = ptr->right;
                    left = false;
                }
            }
            if (ptr == nullptr) return root;
            else if (ptr->left==nullptr || ptr->right==nullptr) {
                if (ptr->left == nullptr) {
                    if (parent != nullptr) {
                        if (left) parent->left = ptr->right;
                        else parent->right = ptr->right;
                    }
                    else root = ptr->right;
                }
                else {
                    if (parent != nullptr) {
                        if (left) parent->left = ptr->left;
                        else parent->right = ptr->left;
                    }
                    else root = ptr->left;
                }
            }
            else {
                auto rptr = ptr->right;
                while (rptr->left != nullptr) rptr = rptr->left;
                rptr->left = ptr->left;
                if (parent != nullptr) {
                    if (left) parent->left = ptr->right;
                    else parent->right = ptr->right;
                }
                else root = ptr->right;
            }
        }
        return root;
    }
};
