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

const int INF = (int)(1e9);
class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        queue<TreeNode*> que;
        vector<int> vals;
        vals.push_back(root->val);
        que.push(root);
        while (!que.empty()) {
            auto vnode = que.front(); que.pop();
            if (vnode->left) {
                que.push(vnode->left);
                vals.push_back(vnode->left->val);
            }
            if (vnode->right) {
                que.push(vnode->right);
                vals.push_back(vnode->right->val);
            }
        }
        sort(vals.begin(), vals.end());
        int res = INF, m = vals.size();
        for (int i=0; i<m-1; ++i) res = min(res, vals[i+1]-vals[i]);
        return res;
    }
};
