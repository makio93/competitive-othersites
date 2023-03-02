// 学習1回目,解説AC3

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
        TreeNode *res = NULL;
        stack<pair<TreeNode*, int>> st;
        st.emplace(root, 0);
        while (!st.empty()) {
            auto vpi = st.top(); st.pop();
            auto pnode = vpi.first; int ccnt = vpi.second;
            if (ccnt==0 && (pnode==p||pnode==q)) {
                if (res == NULL) res = pnode;
                else break;
            }
            if (ccnt < 2) {
                st.emplace(pnode, ccnt+1);
                auto cnode = (ccnt == 0) ? pnode->left : pnode->right;
                if (cnode != NULL) st.emplace(cnode, 0);
            }
            else {
                if (res!=NULL && res==pnode) res = st.top().first;
            }
        }
        return res;
    }
};
