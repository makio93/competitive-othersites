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

class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        queue<TreeNode*> que;
        que.push(root);
        int val = 1, res = -1;
        while (!que.empty() && res == -1) {
            int qi = que.size();
            while (qi--) {
                bool is_leaf = true;
                if (que.front()->left) is_leaf = false, que.push(que.front()->left);
                if (que.front()->right) is_leaf = false, que.push(que.front()->right);
                que.pop();
                if (is_leaf) res = val;
            }
            ++val;
        }
        return res;
    }
};
