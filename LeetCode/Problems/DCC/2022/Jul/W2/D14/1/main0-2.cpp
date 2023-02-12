// 学習1回目,自力AC2

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        unordered_map<int, int> ids;
        for (int i=0; i<n; ++i) ids[inorder[i]] = i;
        auto build = [&](auto build, int len, int pl=0, int il=0) -> TreeNode* {
            if (len == 0) return (TreeNode*)nullptr;
            auto vnode = new TreeNode(preorder[pl]);
            int ic = ids[preorder[pl]], llen = ic - il, rlen = len - llen - 1;
            vnode->left = build(build, llen, pl+1, il);
            vnode->right = build(build, rlen, pl+llen+1, ic+1);
            return vnode;
        };
        return build(build, n);
    }
};
