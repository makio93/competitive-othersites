// 学習1回目,解説AC1

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

const int INF = (int)(1e9);
class Solution {
public:
    int minCameraCover(TreeNode* root) {
        auto dfs = [](auto dfs, TreeNode* node) -> tuple<int, int, int> {
            if (node == nullptr) return make_tuple(0, 0, INF);
            auto lval = dfs(dfs, node->left), rval = dfs(dfs, node->right);
            return make_tuple(get<1>(lval) + get<1>(rval), 
                min(get<2>(lval)+min(get<1>(rval),get<2>(rval)), get<2>(rval)+min(get<1>(lval),get<2>(lval))), 
                1 + min({ get<0>(lval), get<1>(lval), get<2>(lval) }) + min({ get<0>(rval), get<1>(rval), get<2>(rval) }));
        };
        auto rtup = dfs(dfs, root);
        return min(get<1>(rtup), get<2>(rtup));
    }
};
