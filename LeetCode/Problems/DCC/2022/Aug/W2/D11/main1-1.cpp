// 解説AC1

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
    bool isValidBST(TreeNode* root) {
        auto search = [](auto search, TreeNode* vnode, TreeNode* lnode=nullptr, TreeNode* rnode=nullptr) -> bool {
            if (vnode == nullptr) return true;
            if ((lnode!=nullptr&&vnode->val<=lnode->val) || (rnode!=nullptr&&vnode->val>=rnode->val)) return false;
            return search(search, vnode->left, lnode, vnode) && search(search, vnode->right, vnode, rnode);
        };
        return search(search, root);
    }
};
