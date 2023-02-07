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
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        TreeNode* res = NULL;
        if (original->val == target->val) return cloned;
        if (original->left != NULL) {
            res = getTargetCopy(original->left, cloned->left, target);
            if (res != NULL) return res;
        }
        if (original->right != NULL) {
            res = getTargetCopy(original->right, cloned->right, target);
            if (res != NULL) return res;
        }
        return res;
    }
};
