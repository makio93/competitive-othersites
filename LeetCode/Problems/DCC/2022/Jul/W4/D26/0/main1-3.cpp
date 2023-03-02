// 解説AC3

#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        stack<pair<TreeNode*, int>> st;
        int lcnt = 0;
        TreeNode *res = NULL;
        st.emplace(root, 2);
        while (!st.empty()) {
            auto pi = st.top(); st.pop();
            TreeNode *vnode = pi.first;
            int di = pi.second;
            if (di > 0) {
                st.emplace(vnode, di-1);
                if (di == 2) {
                    if (vnode==p || vnode==q) {
                        if (lcnt > 0) return res;
                        else {
                            ++lcnt;
                            res = vnode;
                        }
                    }
                    if (vnode->left != NULL) st.emplace(vnode->left, 2);
                }
                else {
                    if (vnode->right != NULL) st.emplace(vnode->right, 2);
                }
            }
            else {
                if (lcnt>0 && res==vnode) res = st.top().first;  
            }
        }
        return res;
    }
};
