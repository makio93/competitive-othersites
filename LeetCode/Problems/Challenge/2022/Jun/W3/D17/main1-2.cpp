// 解説AC2

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
    int minCameraCover(TreeNode* root) {
        int res = 0;
        unordered_set<TreeNode*> covered;
        covered.insert((TreeNode*)nullptr);
        auto dfs = [&](auto dfs, TreeNode* vnode, TreeNode* pnode) -> void {
            if (vnode != nullptr) {
                dfs(dfs, vnode->left, vnode);
                dfs(dfs, vnode->right, vnode);
                if (covered.find(vnode->left)==covered.end() || covered.find(vnode->right)==covered.end() || 
                    (pnode==nullptr&&covered.find(vnode)==covered.end())) {
                    ++res;
                    covered.insert(vnode);
                    covered.insert(pnode);
                    covered.insert(vnode->left);
                    covered.insert(vnode->right);
                }
            }
        };
        dfs(dfs, root, nullptr);
        return res;
    }
};
