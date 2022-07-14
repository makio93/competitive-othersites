// 解説AC1-0

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
        auto f = [&](auto f, int pid, int left, int right) -> TreeNode* {
            TreeNode* ret = nullptr;
            if (left > right) return ret;
            ret = new TreeNode(preorder[pid]);
            ret->left = f(f, pid+1, left, ids[preorder[pid]]-1);
            ret->right = f(f, pid+ids[preorder[pid]]-left+1, ids[preorder[pid]]+1, right);
            return ret;
        };
        return f(f, 0, 0, n-1);
    }
};
