// 自力AC

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
        unordered_map<int, int> sums;
        function<void(TreeNode*,int)> dfs = [&](TreeNode* vnode, int dep) {
            sums[dep] += vnode->val;
            if (vnode->left) dfs(vnode->left, dep+1);
            if (vnode->right) dfs(vnode->right, dep+1);
        };
        dfs(root, 1);
        pair<int, int> mval = { -INF, 1 };
        for (const auto& pi : sums) mval = max(mval, { pi.second, -pi.first });
        return -mval.second;
    }
};
