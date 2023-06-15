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

const int INF = (int)(2e9);
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> que;
        pair<int, int> mval = { -INF, 1 };
        int dep = 1;
        que.push(root);
        while (!que.empty()) {
            int qi = que.size(), sum = 0;
            for (int i=0; i<qi; ++i) {
                auto vnode = que.front(); que.pop();
                sum += vnode->val;
                if (vnode->left) que.push(vnode->left);
                if (vnode->right) que.push(vnode->right);
            }
            mval = max(mval, { sum, -dep });
            ++dep;
        }
        return -mval.second;
    }
};
