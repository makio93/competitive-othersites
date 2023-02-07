// 解説AC1

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
        auto dfs = [](auto dfs, TreeNode* vnode) -> tuple<int, int, int> {
            if (vnode == nullptr) return make_tuple(0, 0, INF);
            auto lres = dfs(dfs, vnode->left), rres = dfs(dfs, vnode->right);
            auto res = make_tuple(0, 0, 0);
            get<0>(res) = get<1>(lres) + get<1>(rres);
            get<1>(res) = min(min(get<1>(lres), get<2>(lres)) + get<2>(rres), 
                min(get<1>(rres), get<2>(rres)) + get<2>(lres));
            get<2>(res) = 1 + min({ get<0>(lres), get<1>(lres), get<2>(lres) })
             + min({ get<0>(rres), get<1>(rres), get<2>(rres) });
            return res;
        };
        auto res = dfs(dfs, root);
        return min(get<1>(res), get<2>(res));
    }
};
