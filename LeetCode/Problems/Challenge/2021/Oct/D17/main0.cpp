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

// 自力TLE

using ll = long long;
class Solution {
    map<pair<TreeNode*, ll>, int> cnts;
    void dfs1(TreeNode* rnode, ll tarSum, bool dig=false) {
        if (!dig && cnts.find({rnode, tarSum})!=cnts.end()) return;
        if (rnode == nullptr) { cnts[{rnode, tarSum}] = 0; return; }
        if (cnts.find({rnode, tarSum}) == cnts.end()) {
            dfs1(rnode->left, tarSum-rnode->val); dfs1(rnode->right, tarSum-rnode->val);
            cnts[{rnode, tarSum}] = (rnode->val==tarSum ? 1 : 0) + cnts[{rnode->left, tarSum-rnode->val}] + cnts[{rnode->right, tarSum-rnode->val}];
        }
        dfs1(rnode->left, tarSum, true); dfs1(rnode->right, tarSum, true);
    }
    ll dfs2(TreeNode* vnode, ll tarSum) {
        if (vnode == nullptr) return 0;
        return cnts[{vnode, tarSum}] + dfs2(vnode->left, tarSum) + dfs2(vnode->right, tarSum);
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        dfs1(root, targetSum, true);
        return (int)dfs2(root, targetSum);
    }
};
