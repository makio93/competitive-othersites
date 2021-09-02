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
    vector<TreeNode*> search(int l, int r) {
        vector<TreeNode*> res;
        if (r-l < 1) {
            res.push_back(nullptr);
            return res;
        }
        else {
            for (int i=l; i<r; ++i) {
                auto lres = search(l, i), rres = search(i+1, r);
                for (auto li : lres) for (auto ri : rres) res.push_back(new TreeNode(i, li, ri));
            }
            return res;
        }
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        return search(1, n+1);
    }
};
