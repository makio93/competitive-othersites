// 学習1回目,解説AC2

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
        stack<TreeNode*> vst, lst, rst;
        auto push = [&](TreeNode* vnode, TreeNode* lnode, TreeNode* rnode) -> void {
            vst.push(vnode); lst.push(lnode); rst.push(rnode);
        };
        auto pop = [&]() -> tuple<TreeNode*, TreeNode*, TreeNode*> {
            tuple<TreeNode*, TreeNode*, TreeNode*> rtup = { vst.top(), lst.top(), rst.top() };
            vst.pop(); lst.pop(); rst.pop();
            return rtup;
        };
        push(root, nullptr, nullptr);
        while (!vst.empty()) {
            auto [vnode, lnode, rnode] = pop();
            if (vnode == nullptr) continue;
            if ((lnode!=nullptr&&vnode->val<=lnode->val) || (rnode!=nullptr&&vnode->val>=rnode->val)) return false;
            push(vnode->right, vnode, rnode);
            push(vnode->left, lnode, vnode);
        }
        return true;
    }
};
