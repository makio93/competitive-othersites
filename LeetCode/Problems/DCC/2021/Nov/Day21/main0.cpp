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
    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int l, int r, int l2) {
        TreeNode* res = nullptr;
        if (l < r) {
            res = new TreeNode(postorder[r-1+l2-l]);
            if (r-l > 1) {
                int c = r-1;
                while (inorder[c] != res->val) --c;
                res->left = build(inorder, postorder, l, c, l2);
                res->right = build(inorder, postorder, c+1, r, c+l2-l);
            }
        }
        return res;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        return build(inorder, postorder, 0, n, 0);
    }
};
