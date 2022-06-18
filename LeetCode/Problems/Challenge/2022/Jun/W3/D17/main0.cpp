// 自力WA

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

const int INF = (int)(1e9);
class Solution {
public:
    int minCameraCover(TreeNode* root) {
        if (root == nullptr) return 0;
        vector<unordered_set<TreeNode*>> cams(3);
        auto dfs = [&](auto dfs, int mi, TreeNode* vnode, TreeNode* pnode=nullptr, int di=0) -> void {
            if (vnode == nullptr) return;
            if (vnode->left==nullptr && vnode->right==nullptr) {
                if (pnode != nullptr) cams[mi].insert(pnode);
                else cams[mi].insert(vnode);
            }
            else {
                if (di%3 == mi) cams[mi].insert(vnode);
                dfs(dfs, mi, vnode->left, vnode, di+1);
                dfs(dfs, mi, vnode->right, vnode, di+1);
            }
        };
        for (int i=0; i<3; ++i) {
            dfs(dfs, i, root);
            if (i == 2) {
                if ((root->left==nullptr||cams[i].find(root->left)==cams[i].end()) && 
                    (root->right==nullptr||cams[i].find(root->right)==cams[i].end())) 
                    cams[i].insert(root);
            }
        }
        int res = INF;
        for (int i=0; i<3; ++i) res = min(res, (int)(cams[i].size()));
        return res;
    }
};
