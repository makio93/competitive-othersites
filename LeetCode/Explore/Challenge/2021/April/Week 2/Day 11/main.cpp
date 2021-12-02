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
    void dfs(pair<int, int>& res, TreeNode* vnode, int d=0) {
        if (vnode == nullptr) return;
        if (vnode->left==nullptr && vnode->right==nullptr) {
            if (d > res.first) res = { d, vnode->val };
            else if (d == res.first) res.second += vnode->val;
        }
        else {
            dfs(res, vnode->left, d+1);
            dfs(res, vnode->right, d+1);
        }
    }
public:
    int deepestLeavesSum(TreeNode* root) {
        pair<int, int> res = { -1, 0 };
        dfs(res, root);
        return res.second;
    }
};

int main(){
    Solution cl;
    return 0;
}
