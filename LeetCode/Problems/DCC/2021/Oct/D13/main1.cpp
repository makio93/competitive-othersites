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

// 解説AC1,O(N)解法

class Solution {
    TreeNode* dfs(vector<int>& vals, int& nid, int rval) {
        if (nid>=vals.size() || vals[nid]>rval) return nullptr;
        auto vnode = new TreeNode(vals[nid]);
        ++nid;
        vnode->left = dfs(vals, nid, vnode->val);
        vnode->right = dfs(vals, nid, rval);
        return vnode;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int sid = 0;
        return dfs(preorder, sid, (int)(1e8));
    }
};
