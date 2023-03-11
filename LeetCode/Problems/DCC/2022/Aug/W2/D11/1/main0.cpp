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

using ll = long long;
class Solution {
    bool check(TreeNode* vnode, ll lval, ll rval) {
        if (vnode == nullptr) return true;
        if ((ll)vnode->val<lval || (ll)vnode->val>rval) return false;
        return check(vnode->left, lval, (ll)vnode->val-1) && check(vnode->right, (ll)vnode->val+1, rval);
    }
public:
    bool isValidBST(TreeNode* root) {
        return check(root, (ll)numeric_limits<int>::min(), (ll)numeric_limits<int>::max());
    }
};
