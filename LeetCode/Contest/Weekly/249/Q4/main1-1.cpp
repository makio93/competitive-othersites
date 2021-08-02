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

// 解説AC1

class Solution {
    const int MIN_V = (int)(-1e9), MAX_V = (int)(1e9);
    unordered_map<int, TreeNode*> rptr;
    bool search(TreeNode* node, pair<int, int> mvals) {
        if (node == nullptr) return true;
        if (node->val<=mvals.first || node->val>=mvals.second) return false;
        if (node->left==nullptr && node->right==nullptr) {
            if (rptr.find(node->val) != rptr.end()) {
                node->left = rptr[node->val]->left;
                node->right = rptr[node->val]->right;
                rptr.erase(node->val);
            }
        }
        return (search(node->left, { mvals.first, node->val }) && search(node->right, { node->val, mvals.second }));
    }
public:
    TreeNode* canMerge(vector<TreeNode*>& trees) {
        int n = trees.size();
        unordered_map<int, int> vcnt;
        rptr = unordered_map<int, TreeNode*>();
        for (int i=0; i<n; ++i) if (trees[i] != nullptr) {
            vcnt[trees[i]->val]++;
            rptr[trees[i]->val] = trees[i];
            if (trees[i]->left != nullptr) vcnt[trees[i]->left->val]++;
            if (trees[i]->right != nullptr) vcnt[trees[i]->right->val]++;
        }
        int rcnt = 0;
        TreeNode* root = nullptr;
        for (int i=0; i<n; ++i) if (trees[i]!=nullptr && vcnt[trees[i]->val]==1) {
            ++rcnt;
            root = trees[i];
        }
        if (rcnt != 1) return (TreeNode*)nullptr;
        rptr.erase(root->val);
        if (search(root, { MIN_V, MAX_V }) && rptr.empty()) return root;
        else return (TreeNode*)nullptr;
    }
};
