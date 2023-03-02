// 学習1回目,自力AC2

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
        stack<TreeNode*> pst, qst;
        auto make_stack = [](stack<TreeNode*>& st, TreeNode* root, TreeNode* target) -> void {
            stack<int> ist;
            st.push(root);
            ist.push(0);
            while (st.top() != target) {
                auto vnode = st.top();
                ist.top()++;
                if (ist.top() == 1) {
                    if (vnode->left != NULL) {
                        st.push(vnode->left);
                        ist.push(0);
                    }
                }
                else if (ist.top() == 2) {
                    if (vnode->right != NULL) {
                        st.push(vnode->right);
                        ist.push(0);
                    }
                }
                else {
                    st.pop();
                    ist.pop();
                }
            }
        };
        make_stack(pst, root, p);
        make_stack(qst, root, q);
        if (pst.size() < qst.size()) swap(pst, qst);
        while (pst.size() > qst.size()) pst.pop();
        while (pst.top() != qst.top()) {
            pst.pop();
            qst.pop();
        }
        return pst.top();
    }
};
