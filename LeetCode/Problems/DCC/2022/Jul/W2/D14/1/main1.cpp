// 学習1回目,解説AC

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
    unordered_map<int, int> ids;
    TreeNode* build(vector<int>::iterator pitr, int li, int ri) {
        if (ri < li) return nullptr;
        auto vnode = new TreeNode(*pitr);
        vnode->left = build(pitr+1, li, ids[*pitr]-1);
        vnode->right = build(pitr+(ids[*pitr]-li)+1, ids[*pitr]+1, ri);
        return vnode;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        for (int i=0; i<n; ++i) ids[inorder[i]] = i;
        return build(preorder.begin(), 0, n-1);
    }
};
