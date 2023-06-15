// 解説AC2

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

const int INF = (int)(2e9);
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        vector<int> sums;
        function<void(TreeNode*,int)> dfs = [&](TreeNode* vnode, int dep) {
            if (!vnode) return;
            if (dep >= (int)(sums.size())) sums.push_back(vnode->val);
            else sums[dep] += vnode->val;
            dfs(vnode->left, dep+1);
            dfs(vnode->right, dep+1);
        };
        dfs(root, 0);
        pair<int, int> mval = { -INF, 1 };
        int m = sums.size();
        for (int i=0; i<m; ++i) mval = max(mval, { sums[i], -(i+1) });
        return -mval.second;
    }
};
