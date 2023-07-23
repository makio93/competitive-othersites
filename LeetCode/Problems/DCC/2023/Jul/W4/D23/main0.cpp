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
    vector<TreeNode*> allPossibleFBT(int n) {
        if (n == 1) return vector<TreeNode*>({ new TreeNode(0) });
        vector<TreeNode*> res;
        for (int li=1; li<n-1; li+=2) {
            int ri = (n-1) - li;
            auto llst = allPossibleFBT(li);
            int llen = llst.size();
            for (int j1=0; j1<llen; ++j1) {
                auto rlst = allPossibleFBT(ri);
                int rlen = rlst.size();
                for (int j2=0; j2<rlen; ++j2) res.push_back(new TreeNode(0, llst[j1], rlst[j2]));
            }
        }
        return res;
    }
};
