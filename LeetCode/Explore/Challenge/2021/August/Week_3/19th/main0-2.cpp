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

// 自力AC,2

class Solution {
    const int mod = (int)(1e9) + 7;
    int tree_sum(TreeNode* node) {
        if (node == nullptr) return 0;
        return (node->val + tree_sum(node->left) + tree_sum(node->right));
    }
    int tar;
    int search(TreeNode* node, pair<int, int>& mval) {
        int res = 0;
        if (node != nullptr) res += (int)node->val + search(node->left, mval) + search(node->right, mval);
        mval = min(mval, { abs(tar-res*2), res });
        return res;
    }
public:
    int maxProduct(TreeNode* root) {
        tar = tree_sum(root);
        pair<int, int> mval = { (int)(1e9), (int)(1e9) };
        search(root, mval);
        return (int)((long long)mval.second * (tar-mval.second) % mod);
    }
};
