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
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        function<int(TreeNode*)> dfs = [&](TreeNode* tnode) -> int {
            if (tnode == nullptr) return -1;
            pair<int, int> cvals = { dfs(tnode->left)+1, dfs(tnode->right)+1 };
            res = max(res, cvals.first+cvals.second);
            return max(cvals.first, cvals.second);
        };
        dfs(root);
        return res;
    }
};
