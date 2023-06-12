// 学習1回目,自力AC

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
    int minCameraCover(TreeNode* root) {
        unordered_map<TreeNode*, int> memo;
        function<void(TreeNode*)> dfs = [&](TreeNode* vnode) {
            if (vnode->left == nullptr && vnode->right == nullptr) memo[vnode] = 0;
            bool zero = false, one = false;
            if (vnode->left != nullptr) {
                dfs(vnode->left);
                if (memo[vnode->left] == 0) zero = true;
                if (memo[vnode->left] == 1) one = true;
            }
            if (vnode->right != nullptr) {
                dfs(vnode->right);
                if (memo[vnode->right] == 0) zero = true;
                if (memo[vnode->right] == 1) one = true;
            }
            if (zero) memo[vnode] = 1;
            else if (one) memo[vnode] = 2;
            else memo[vnode] = (vnode == root ? 1 : 0);
        };
        dfs(root);
        int res = 0;
        for (const auto& pi : memo) if (pi.second == 1) ++res;
        return res;
    }
};
