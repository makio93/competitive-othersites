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

// 自力AC,あまり良くない解答

class Solution {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> res;
        stack<TreeNode*> stk;
        if (root1 != nullptr) {
            res.push_back(root1->val);
            stk.push(root1);
        }
        if (root2 != nullptr) {
            res.push_back(root2->val);
            stk.push(root2);
        }
        while (!stk.empty()) {
            auto ptr = stk.top(); stk.pop();
            if (ptr->left != nullptr) {
                res.push_back(ptr->left->val);
                stk.push(ptr->left);
            }
            if (ptr->right != nullptr) {
                res.push_back(ptr->right->val);
                stk.push(ptr->right);
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};
