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
        unordered_map<TreeNode*, TreeNode*> parents;
        stack<TreeNode*> nst;
        nst.push(root);
        parents[root] = NULL;
        while (parents.find(p)==parents.end() || parents.find(q)==parents.end()) {
            TreeNode* vnode = nst.top(); nst.pop();
            if (vnode->left) {
                nst.push(vnode->left);
                parents[vnode->left] = vnode;
            }
            if (vnode->right) {
                nst.push(vnode->right);
                parents[vnode->right] = vnode;
            }
        }
        unordered_set<TreeNode*> ast;
        while (p) {
            ast.insert(p);
            p = parents[p];
        }
        while (ast.find(q) == ast.end()) q = parents[q];
        return q;
    }
};
