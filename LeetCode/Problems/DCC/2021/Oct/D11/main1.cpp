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

// 解説AC1

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        function<int(TreeNode*,int&)> dfs = [&](TreeNode* tnode, int& mval) -> int {
            if (tnode == nullptr) return 0;
            pair<int, int> cvals = { dfs(tnode->left, mval), dfs(tnode->right, mval) };
            mval = max(mval, cvals.first+cvals.second);
            return max(cvals.first, cvals.second) + 1;
        };
        int res = 0;
        dfs(root, res);
        return res;
    }
};
