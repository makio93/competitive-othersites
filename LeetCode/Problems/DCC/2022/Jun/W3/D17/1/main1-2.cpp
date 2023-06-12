// 学習1回目,解説AC2

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
        unordered_set<TreeNode*> covered;
        covered.insert(nullptr);
        int res = 0;
        function<void(TreeNode*,TreeNode*)> dfs = [&](TreeNode* vnode, TreeNode* pnode) {
            if (vnode == nullptr) return;
            dfs(vnode->left, vnode);
            dfs(vnode->right, vnode);
            if ((pnode==nullptr && covered.find(vnode)==covered.end()) || 
                    covered.find(vnode->left) == covered.end() || 
                    covered.find(vnode->right) == covered.end()) {
                ++res;
                covered.insert(vnode);
                covered.insert(pnode);
                covered.insert(vnode->left);
                covered.insert(vnode->right);
            }
        };
        dfs(root, nullptr);
        return res;
    }
};
