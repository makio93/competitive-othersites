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
    const int mod = (int)(1e9) + 7;
    set<int> vals;
    int calc(TreeNode* node) {
        int res = 0;
        if (node != nullptr) res += (int)node->val + calc(node->left) + calc(node->right);
        vals.insert(res);
        return res;
    }
public:
    int maxProduct(TreeNode* root) {
        vals = set<int>();
        int sum = calc(root);
        pair<int, int> mval = { (int)(1e9), (int)(1e9) };
        auto itr = vals.upper_bound(sum/2);
        if (itr != vals.end()) mval = min(mval, { abs((*itr)-(sum-(*itr))), *itr });
        if (itr != vals.begin()) {
            auto itr2 = prev(itr);
            mval = min(mval, { abs((*itr2)-(sum-(*itr2))), *itr2 });
        }
        return (int)((long long)mval.second * (sum-mval.second) % mod);
    }
};
