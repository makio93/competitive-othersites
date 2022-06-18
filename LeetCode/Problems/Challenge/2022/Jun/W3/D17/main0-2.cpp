// 自力,ヒント有,AC

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

const int INF = (int)(1e8);
class Solution {
public:
    int minCameraCover(TreeNode* root) {
        if (root == nullptr) return 0;
        map<pair<TreeNode*, int>, int> memo;
        auto dfs = [&](auto dfs, TreeNode* vnode, int sid) -> int {
            if (memo.find({vnode, sid}) != memo.end()) return memo[{vnode, sid}];
            int res = 0;
            if (sid == 0) {
                if (vnode->left != nullptr) res = min(INF, res + dfs(dfs, vnode->left, 1));
                if (vnode->right != nullptr) res = min(INF, res + dfs(dfs, vnode->right, 1));
            }
            else if (sid == 1) {
                res = INF;
                if (vnode->left!=nullptr && vnode->right!=nullptr) {
                    res = min(res, dfs(dfs, vnode->left, 2) + dfs(dfs, vnode->right, 2));
                    res = min(res, dfs(dfs, vnode->left, 2) + dfs(dfs, vnode->right, 1));
                    res = min(res, dfs(dfs, vnode->left, 1) + dfs(dfs, vnode->right, 2));
                }
                else if (vnode->left!=nullptr || vnode->right!=nullptr) {
                    if (vnode->left != nullptr) res = min(res, dfs(dfs, vnode->left, 2));
                    if (vnode->right != nullptr) res = min(res, dfs(dfs, vnode->right, 2));
                }
            }
            else {
                int lval = INF, rval = INF;
                if (vnode->left != nullptr) for (int i=0; i<3; ++i) lval = min(lval, dfs(dfs, vnode->left, i));
                else lval = 0;
                if (vnode->right != nullptr) for (int i=0; i<3; ++i) rval = min(rval, dfs(dfs, vnode->right, i));
                else rval = 0;
                res = min(INF, 1+lval+rval);
            }
            return memo[{vnode, sid}] = res;
        };
        int ans = INF;
        for (int i=1; i<3; ++i) ans = min(ans, dfs(dfs, root, i));
        return ans;
    }
};
