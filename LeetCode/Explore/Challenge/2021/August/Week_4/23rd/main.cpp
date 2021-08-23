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

// 自力AC

class Solution {
    void search(TreeNode* node, unordered_map<int, int>& vcnt) {
        if (node == nullptr) return;
        vcnt[node->val]++;
        search(node->left, vcnt);
        search(node->right, vcnt);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        unordered_map<int, int> vcnt;
        search(root, vcnt);
        bool ok = false;
        for (auto p : vcnt) if (vcnt.find(k-p.first) != vcnt.end()) {
            if (p.first == k-p.first) { if (p.second >= 2) ok = true; }
            else ok = true;
        }
        return ok;
    }
};
