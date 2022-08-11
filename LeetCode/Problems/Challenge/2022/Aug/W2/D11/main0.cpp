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

using ll = long long;

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        auto search = [](auto search, TreeNode* vnode, ll lval, ll rval) -> bool {
            if (vnode == nullptr) return true;
            return (vnode->val>=lval && vnode->val<=rval && search(search, vnode->left, lval, (ll)vnode->val-1) 
                && search(search, vnode->right, (ll)vnode->val+1, rval));
        };
        return search(search, root, numeric_limits<int>::min(), numeric_limits<int>::max());
    }
};
