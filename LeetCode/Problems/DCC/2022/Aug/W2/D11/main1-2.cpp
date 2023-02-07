// 解説AC2

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
    bool isValidBST(TreeNode* root) {
        stack<tuple<TreeNode*, TreeNode*, TreeNode*>> stk;
        stk.emplace(root, nullptr, nullptr);
        while (!stk.empty()) {
            auto tup = stk.top(); stk.pop();
            auto vnode = get<0>(tup), lnode = get<1>(tup), rnode = get<2>(tup);
            if (vnode == nullptr) continue;
            if ((lnode!=nullptr&&vnode->val<=lnode->val) || (rnode!=nullptr&&vnode->val>=rnode->val)) return false;
            stk.emplace(vnode->right, vnode, rnode);
            stk.emplace(vnode->left, lnode, vnode);
        }
        return true;
    }
};
