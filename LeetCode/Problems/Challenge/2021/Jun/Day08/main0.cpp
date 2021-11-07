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

// 自力AC

class Solution {
    TreeNode* dfs(TreeNode*& vnode, int lid1, int lid2, int len, vector<int>& preorder, vector<int>& inorder) {
        if (len <= 0) return vnode;
        vnode = new TreeNode(preorder[lid1]);
        if (len == 1) return vnode;
        int tid = lid1;
        for (int i=0; i<len; ++i) if (preorder[lid1] == inorder[lid2+i]) {
            tid = i;
            break;
        }
        if (tid > 0) dfs(vnode->left, lid1+1, lid2, tid, preorder, inorder);
        if (tid+1 >= len) return vnode;
        dfs(vnode->right, lid1+tid+1, lid2+tid+1, len-(tid+1), preorder, inorder);
        return vnode;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        TreeNode* root = (TreeNode*)nullptr;
        return dfs(root, 0, 0, n, preorder, inorder);
    }
};
