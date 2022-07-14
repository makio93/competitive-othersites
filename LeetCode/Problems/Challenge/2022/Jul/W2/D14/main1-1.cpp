// 解説AC1

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
        int pid = 0;
        auto f = [&](auto f, int left, int right) -> TreeNode* {
            TreeNode* ret = nullptr;
            if (left > right) return ret;
            int rval = preorder[pid];
            ret = new TreeNode(rval);
            ++pid;
            ret->left = f(f, left, ids[rval]-1);
            ret->right = f(f, ids[rval]+1, right);
            return ret;
        };
        return f(f, 0, n-1);
    }
};
