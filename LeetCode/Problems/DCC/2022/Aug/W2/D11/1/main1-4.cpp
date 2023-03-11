// 学習1回目,解説AC4

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
        stack<TreeNode*> st;
        TreeNode *pnode = nullptr, *vnode = root;
        while (!st.empty() || vnode!=nullptr) {
            while (vnode != nullptr) {
                st.push(vnode);
                vnode = vnode->left;
            }
            vnode = st.top(); st.pop();
            if (pnode!=nullptr && vnode->val<=pnode->val) return false;
            pnode = vnode;
            vnode = vnode->right;
        }
        return true;
    }
};
