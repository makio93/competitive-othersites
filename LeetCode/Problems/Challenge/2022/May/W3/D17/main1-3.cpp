// 解説AC3

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
        queue<TreeNode*> oq, cq;
        oq.push(original); cq.push(cloned);
        while (!oq.empty()) {
            auto op = oq.front(); oq.pop();
            auto cp = cq.front(); cq.pop();
            if (op->val == target->val) return cp;
            if (op->left != NULL) { oq.push(op->left); cq.push(cp->left); }
            if (op->right != NULL) { oq.push(op->right); cq.push(cp->right); }
        }
        return NULL;
    }
};
