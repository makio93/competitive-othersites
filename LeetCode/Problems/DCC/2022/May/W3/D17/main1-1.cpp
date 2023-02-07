// 解説AC1

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
        auto dfs = [&](auto dfs, TreeNode* on, TreeNode* cn, int tar) -> TreeNode* {
            if (on == NULL) return NULL;
            if (on->left != NULL) {
                auto rp = dfs(dfs, on->left, cn->left, tar);
                if (rp != NULL) return rp;
            }
            if (on->val == tar) return cn;
            if (on->right != NULL) {
                auto rp = dfs(dfs, on->right, cn->right, tar);
                if (rp != NULL) return rp;
            }
            return NULL;
        };
        return dfs(dfs, original, cloned, target->val);
    }
};
