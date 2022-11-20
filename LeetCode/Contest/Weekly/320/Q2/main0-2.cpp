// 本番AC

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
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        int n = queries.size();
        vector<int> vals;
        auto dfs = [&](auto dfs, TreeNode* node) -> void {
            if (node == nullptr) return;
            vals.push_back(node->val);
            dfs(dfs, node->left);
            dfs(dfs, node->right);
        };
        dfs(dfs, root);
        sort(vals.begin(), vals.end());
        vector<vector<int>> answer(n, vector<int>(2, -1));
        int m = vals.size();
        for (int i=0; i<n; ++i) {
            int li = upper_bound(vals.begin(), vals.end(), queries[i]) - vals.begin();
            if (li-1 >= 0) answer[i][0] = vals[li-1];
            int ri = lower_bound(vals.begin(), vals.end(), queries[i]) - vals.begin();
            if (ri < m) answer[i][1] = vals[ri];
        }
        return answer;
    }
};
