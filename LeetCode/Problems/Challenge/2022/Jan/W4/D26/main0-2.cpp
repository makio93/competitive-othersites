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

// 自力AC2,2本同時に探索する

class Solution {
    void add(vector<int>& vec, TreeNode* vnode, int lval, int rval) {
        if (vnode == nullptr) return;
        if (rval < lval) return;
        add(vec, vnode->left, lval, min(rval,vnode->val));
        if (vnode->val>=lval && vnode->val<=rval) vec.push_back(vnode->val);
        add(vec, vnode->right, max(lval,vnode->val), rval);
    }
    void combine(vector<int>& vec, TreeNode* vnode1, TreeNode* vnode2, int lval, int rval) {
        if (rval < lval) return;
        if (vnode1==nullptr || vnode2==nullptr) {
            if (vnode1 != nullptr) add(vec, vnode1, lval, rval);
            else if (vnode2 != nullptr) add(vec, vnode2, lval, rval);
        }
        else {
            if (vnode1->val > vnode2->val) swap(vnode1, vnode2);
            combine(vec, vnode1->left, vnode2->left, lval, vnode1->val);
            if (vnode1->val>=lval && vnode1->val<=rval) {
                vec.push_back(vnode1->val);
                add(vec, vnode1->right, vnode1->val, vnode1->val);
            }
            combine(vec, vnode1->right, vnode2->left, max(lval,vnode1->val+1), min(rval,vnode2->val));
            if (vnode2->val>=lval && vnode2->val<=rval) {
                vec.push_back(vnode2->val);
                add(vec, vnode2->right, vnode2->val, vnode2->val);
            }
            combine(vec, vnode1->right, vnode2->right, max(lval,vnode2->val+1), rval);
        }
    }
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> res;
        combine(res, root1, root2, -(int)(1e5), (int)(1e5));
        return res;
    }
};
