// 本番WA

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
    int search(TreeNode* node, int target, bool upper) {
        if (node == nullptr) return -1;
        if (node->val == target) return node->val;
        if (!upper) {
            if (node->val < target) {
                int rval = search(node->right, target, upper);
                if (rval == -1) return node->val;
                else return rval;
            }
            else return search(node->left, target, upper);
        }
        else {
            if (node->val > target) {
                int rval = search(node->left, target, upper);
                if (rval == -1) return node->val;
                else return rval;
            }
            else return search(node->right, target, upper);
        }
    }
public:
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        int n = queries.size();
        vector<vector<int>> answer(n, vector<int>(2));
        for (int i=0; i<n; ++i) answer[i] = { search(root, queries[i], false), search(root, queries[i], true) };
        return answer;
    }
};
