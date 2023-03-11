// 学習1回目,解説AC1

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
    bool check(TreeNode* vnode, TreeNode* lnode=nullptr, TreeNode* rnode=nullptr) {
        if (vnode == nullptr) return true;
        if ((lnode!=nullptr&&vnode->val<=lnode->val) || (rnode!=nullptr&&vnode->val>=rnode->val)) return false;
        return check(vnode->left, lnode, vnode) && check(vnode->right, vnode, rnode);
    }
public:
    bool isValidBST(TreeNode* root) {
        return check(root);
    }
};
