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
    TreeNode* dfs(vector<int>& vals, int& nid, int lval, int rval) {
        if (nid>=vals.size() || lval>=rval || vals[nid]<lval || vals[nid]>=rval) return nullptr;
        auto vnode = new TreeNode(vals[nid]);
        ++nid;
        vnode->left = dfs(vals, nid, lval, vnode->val);
        vnode->right = dfs(vals, nid, vnode->val+1, rval);
        return vnode;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int sid = 0;
        return dfs(preorder, sid, 1, (int)(1e8)+1);
    }
};
