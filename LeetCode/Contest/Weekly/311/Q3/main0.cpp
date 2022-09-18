// 本番AC

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
    TreeNode* reverseOddLevels(TreeNode* root) {
        vector<TreeNode*> que;
        int dcnt = 0;
        que.push_back(root);
        while (!que.empty()) {
            vector<TreeNode*> nque;
            int len = que.size();
            if (dcnt%2 == 1) for (int i=0; i<len/2; ++i) swap(que[i]->val, que[len-1-i]->val);
            for (int i=0; i<len; ++i) {
                if (que[i]->left != nullptr) nque.push_back(que[i]->left);
                if (que[i]->right != nullptr) nque.push_back(que[i]->right);
            }
            swap(nque, que);
            ++dcnt;
        }
        return root;
    }
};
