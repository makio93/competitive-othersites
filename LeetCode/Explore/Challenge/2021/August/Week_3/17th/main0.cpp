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
    int search(TreeNode* node, int maxval) {
        if (node == nullptr) return 0;
        int res = (node->val >= maxval) ? 1 : 0;
        maxval = max(maxval, node->val);
        res += search(node->left, maxval) + search(node->right, maxval);
        return res;
    }
public:
    int goodNodes(TreeNode* root) {
        return search(root, (int)(-1e9));
    }
};
