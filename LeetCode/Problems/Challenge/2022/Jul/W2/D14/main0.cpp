// 自力AC

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        auto f = [&](auto f, int len, int pid=0, int iid=0) -> TreeNode* {
            TreeNode* ret = nullptr;
            if (len == 0) return ret;
            ret = new TreeNode(preorder[pid]);
            int ri = iid;
            while (inorder[ri] != preorder[pid]) ++ri;
            int llen = ri-iid, rlen = len - llen - 1;
            ret->left = f(f, llen, pid+1, iid);
            ret->right = f(f, rlen, pid+llen+1, iid+llen+1);
            return ret;
        };
        return f(f, n);
    }
};
