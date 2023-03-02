// 学習1回目,解説AC2

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
        stack<TreeNode*> st;
        unordered_map<TreeNode*, TreeNode*> par;
        st.push(root);
        par[root] = NULL;
        while (par.find(p)==par.end() || par.find(q)==par.end()) {
            auto vnode = st.top(); st.pop();
            if (vnode->left != NULL) {
                st.push(vnode->left);
                par[vnode->left] = vnode;
            }
            if (vnode->right != NULL) {
                st.push(vnode->right);
                par[vnode->right] = vnode;
            }
        }
        unordered_set<TreeNode*> pnode;
        while (p != NULL) {
            pnode.insert(p);
            p = par[p];
        }
        while (pnode.find(q) == pnode.end()) q = par[q];
        return q;
    }
};
