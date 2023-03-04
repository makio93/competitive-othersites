// 自力AC1

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
    TreeNode* search(TreeNode* vnode) {
        TreeNode* ltail = (vnode->left != nullptr) ? search(vnode->left) : nullptr;
        TreeNode* rtail = (vnode->right != nullptr) ? search(vnode->right) : nullptr;
        if (ltail!=nullptr && rtail!=nullptr) {
            ltail->right = vnode->right;
            vnode->right = vnode->left;
            vnode->left = nullptr;
            return rtail;
        }
        else if (ltail != nullptr) {
            vnode->right = vnode->left;
            vnode->left = nullptr;
            return ltail;
        }
        else if (rtail != nullptr) return rtail;
        else return vnode;
    }
public:
    void flatten(TreeNode* root) {
        if (root == nullptr) return;
        search(root);
    }
};
