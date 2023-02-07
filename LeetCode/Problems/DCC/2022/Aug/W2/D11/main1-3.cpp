// 解説AC3

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
        TreeNode* pnode = nullptr;
        auto dfs = [&](auto dfs, TreeNode* vnode) -> bool {
            if (vnode == nullptr) return true;
            if (!dfs(dfs, vnode->left)) return false;
            if (pnode!=nullptr && vnode->val<=pnode->val) return false;
            pnode = vnode;
            return dfs(dfs, vnode->right);
        };
        return dfs(dfs, root);
    }
};
