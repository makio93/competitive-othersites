// 解説AC1

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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if (k == 0) return { target->val };
        unordered_map<TreeNode*, TreeNode*> parents;
        function<void(TreeNode*)> dfs = [&](TreeNode* vnode) {
            if (vnode->left) {
                parents[vnode->left] = vnode;
                dfs(vnode->left);
            }
            if (vnode->right) {
                parents[vnode->right] = vnode;
                dfs(vnode->right);
            }
        };
        parents[root] = nullptr;
        dfs(root);
        queue<TreeNode*> que;
        unordered_set<TreeNode*> visited;
        que.push(target);
        visited.insert(target);
        while (!que.empty()) {
            int qi = que.size();
            while (qi--) {
                auto vnode = que.front(); que.pop();
                if (vnode->left && visited.find(vnode->left) == visited.end()) {
                    que.push(vnode->left);
                    visited.insert(vnode->left);
                }
                if (vnode->right && visited.find(vnode->right) == visited.end()) {
                    que.push(vnode->right);
                    visited.insert(vnode->right);
                }
                if (parents[vnode] && visited.find(parents[vnode]) == visited.end()) {
                    que.push(parents[vnode]);
                    visited.insert(parents[vnode]);
                }
            }
            --k;
            if (k == 0) {
                vector<int> res;
                while (!que.empty()) {
                    res.push_back(que.front()->val);
                    que.pop();
                }
                return res;
            }
        }
        return {};
    }
};
