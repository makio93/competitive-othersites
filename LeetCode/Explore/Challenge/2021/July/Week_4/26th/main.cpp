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
    vector<int> array;
    TreeNode* make_bst(int l, int r) {
        if (l>r) return nullptr;
        int c = (l+r+1) / 2;
        return (new TreeNode(array[c], make_bst(l, c-1), make_bst(c+1, r)));
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        array = nums;
        return make_bst(0, n-1);
    }
};
