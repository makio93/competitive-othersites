// 解説AC2

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
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        auto vnode = root;
        while ((p->val<vnode->val&&q->val<vnode->val) || (p->val>vnode->val&&q->val>vnode->val)) {
            if (p->val<vnode->val&&q->val<vnode->val) vnode = vnode->left;
            else vnode = vnode->right;
        }
        return vnode;
    }
};
