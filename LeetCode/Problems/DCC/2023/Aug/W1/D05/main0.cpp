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
    vector<TreeNode*> generateTrees(int n) {
        function<vector<TreeNode*>(int, int)> f = [&](int li, int ri) {
            vector<TreeNode*> vlst;
            if (ri < li) {
                vlst.push_back(nullptr);
                return vlst;
            }
            if (li == ri) {
                vlst.push_back(new TreeNode(li));
                return vlst;
            }
            for (int ci=li; ci<=ri; ++ci) {
                auto llst = f(li, ci-1), rlst = f(ci+1, ri);
                for (const auto& lv : llst) for (const auto& rv : rlst) vlst.push_back(new TreeNode(ci, lv, rv));
            }
            return vlst;
        };
        return f(1, n);
    }
};
