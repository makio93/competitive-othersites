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

// 自力AC2,非再帰での実装

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty()) {
            auto ptr = st.top(); st.pop();
            if (ptr == nullptr) continue;
            st.push(ptr->right);
            if (ptr->left == nullptr) res.push_back(ptr->val);
            else st.push(new TreeNode(ptr->val));
            st.push(ptr->left);
        }
        return res;
    }
};
