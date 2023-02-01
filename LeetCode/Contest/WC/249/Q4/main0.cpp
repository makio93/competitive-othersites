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

// 本番WA

class Solution {
    bool dfs(TreeNode* node, pair<int, int>& mvals) {
        if (node == nullptr) return true;
        pair<int, int> lmval = { (int)(1e9), -1 }, rmval = { (int)(1e9), -1 };
        auto lres = dfs(node->left, lmval);
        auto rles = dfs(node->right, rmval);
        if (!lres || !rles) return false;
        mvals.first = min({ lmval.first, node->val, rmval.first });
        mvals.second = max({ lmval.second, node->val, rmval.second });
        if (lmval.second<node->val && rmval.first>node->val) return true;
        else return false;
    }
public:
    TreeNode* canMerge(vector<TreeNode*>& trees) {
        int n = trees.size();
        unordered_map<int, int> treeid;
        for (int i=0; i<n; ++i) treeid[trees[i]->val] = i;
        vector<bool> ischild(n);
        for (int i=0; i<n; ++i) {
            if (trees[i]->left != nullptr) {
                if (treeid.find(trees[i]->left->val) != treeid.end()) {
                    int lval = trees[i]->left->val, cid = treeid[lval];
                    trees[i]->left = trees[cid];
                    ischild[cid] = true;
                    treeid.erase(lval);
                }
            }
            if (trees[i]->right != nullptr) {
                if (treeid.find(trees[i]->right->val) != treeid.end()) {
                    int rval = trees[i]->right->val, cid = treeid[rval];
                    trees[i]->right = trees[cid];
                    ischild[cid] = true;
                    treeid.erase(rval);
                }
            }
        }
        int vcnt = 0;
        for (int i=0; i<n; ++i) if (!ischild[i]) ++vcnt;
        if (vcnt != 1) return (TreeNode*)(nullptr);
        TreeNode* root;
        for (int i=0; i<n; ++i) if (!ischild[i]) root = trees[i];
        pair<int, int> tpval = { (int)(1e9), -1 };
        bool ok = (dfs(root, tpval) && (tpval==make_pair((int)(1e9), -1) || tpval.first<tpval.second));
        if (ok) return root;
        else return (TreeNode*)(nullptr);
    }
};
