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
        function<tuple<int,int,int>(TreeNode*)> dfs = [&](TreeNode* vnode) {
            if (vnode == nullptr) return make_tuple(0, 0, INF);
            auto lt = dfs(vnode->left), rt = dfs(vnode->right);
            int ml = min(get<1>(lt), get<2>(lt)), mr = min(get<1>(rt), get<2>(rt));
            int d0 = get<1>(lt) + get<1>(rt);
            int d1 = min(get<2>(lt) + mr, ml + get<2>(rt));
            int d2 = 1 + min(get<0>(lt), ml) + min(get<0>(rt), mr);
            return make_tuple(d0, d1, d2);
        };
        auto tdp = dfs(root);
        return min(get<1>(tdp), get<2>(tdp));
    }
};
