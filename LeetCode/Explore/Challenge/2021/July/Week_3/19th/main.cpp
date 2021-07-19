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
    int lca(TreeNode* vnode, TreeNode*& rnode, int val1, int val2) {
        if (vnode == nullptr) return 0;
        TreeNode *tnode1 = nullptr, *tnode2 = nullptr;
        int rval1 = lca(vnode->left, tnode1, val1, val2), rval2 = lca(vnode->right, tnode2, val1, val2);
        if (vnode->val == val1) {
            if (((rval1>>1)&1) || ((rval2>>1)&1)) {
                rnode = vnode;
                return (1<<2) - 1;
            }
            else return 1;
        }
        else if (vnode->val == val2) {
            if ((rval1&1) || (rval2&1)) {
                rnode = vnode;
                return (1<<2) - 1;
            }
            else return (1<<1);
        }
        else {
            if (rval1 == (1<<2)-1) {
                rnode = tnode1;
                return rval1;
            }
            else if (rval2 == (1<<2)-1) {
                rnode = tnode2;
                return rval2;
            }
            else if ((rval1|rval2) == (1<<2)-1) {
                rnode = vnode;
                return (1<<2) - 1;
            }
            else return (rval1|rval2);
        }
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* res = nullptr;
        lca(root, res, p->val, q->val);
        return res;
    }
};
