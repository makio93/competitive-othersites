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
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        stack<TreeNode*> ost, cst;
        TreeNode *op = original, *cp = cloned;
        while (!ost.empty() || op!=NULL) {
            while (op != NULL) {
                ost.push(op); cst.push(cp);
                op = op->left; cp = cp->left;
            }
            op = ost.top(); ost.pop();
            cp = cst.top(); cst.pop();
            if (op->val == target->val) return cp;
            op = op->right; cp = cp->right;
        }
        return cp;
    }
};
