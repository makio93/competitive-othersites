// 自力AC

#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    bool search(TreeNode* vnode, TreeNode* tnode) {
        if (vnode == nullptr) return false;
        if (vnode == tnode) return true;
        return search(vnode->left, tnode) || search(vnode->right, tnode);
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root==p || root==q) return root;
        else {
            if (search(root->left, p) && search(root->left, q)) return lowestCommonAncestor(root->left, p, q);
            else if (search(root->right, p) && search(root->right, q)) return lowestCommonAncestor(root->right, p, q);
            else return root;
        }
    }
};
