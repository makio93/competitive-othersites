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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        auto calc = [&](auto calc, int li, int ri) -> TreeNode* {
            if (li >= ri) return nullptr;
            auto vnode = new TreeNode();
            if (ri-li == 1) vnode->val = nums[li];
            else {
                int ci = li + (ri-li) / 2;
                vnode->val = nums[ci];
                vnode->left = calc(calc, li, ci);
                vnode->right = calc(calc, ci+1, ri);
            }
            return vnode;
        };
        return calc(calc, 0, n);
    }
};
