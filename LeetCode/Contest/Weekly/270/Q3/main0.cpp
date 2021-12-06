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

bool path(string& sres, TreeNode* vnode, int tval) {
    if (vnode == nullptr) return false;
    if (vnode->val == tval) return true;
    else {
        sres.push_back('L');
        if (path(sres, vnode->left, tval)) return true;
        sres.pop_back();
        sres.push_back('R');
        if (path(sres, vnode->right, tval)) return true;
        sres.pop_back();
        return false;
    }
}

int dfs(string& sres, TreeNode* vnode, int tval1, int tval2) {
    int res = 0;
    if (vnode == nullptr) return res;
    int lres = dfs(sres, vnode->left, tval1, tval2);
    if (lres == (1<<2)-1) return lres;
    int rres = dfs(sres, vnode->right, tval1, tval2);
    if (rres == (1<<2)-1) return rres;
    if (vnode->val == tval1) {
        res |= 1;
        if ((res|lres) == (1<<2)-1) {
            string lsres = "L";
            path(lsres, vnode->left, tval2);
            sres = lsres;
            return (res|lres);
        }
        else if ((res|rres) == (1<<2)-1) {
            string rsres = "R";
            path(rsres, vnode->right, tval2);
            sres = rsres;
            return (res|rres);
        }
    }
    else if (vnode->val == tval2) {
        res |= (1<<1);
        if ((res|lres) == (1<<2)-1) {
            string lsres = "L";
            path(lsres, vnode->left, tval1);
            for (char& ci : lsres) ci = 'U';
            sres = lsres;
            return (res|lres);
        }
        else if ((res|rres) == (1<<2)-1) {
            string rsres = "R";
            path(rsres, vnode->right, tval1);
            for (char& ci : rsres) ci = 'U';
            sres = rsres;
            return (res|rres);
        }
    }
    else {
        if ((lres|rres) == (1<<2)-1) {
            string lsres = "L", rsres = "R";
            if (lres&1) {
                path(lsres, vnode->left, tval1);
                for (char& ci : lsres) ci = 'U';
                path(rsres, vnode->right, tval2);
                sres = lsres + rsres;
            }
            else {
                path(lsres, vnode->left, tval2);
                path(rsres, vnode->right, tval1);
                for (char& ci : rsres) ci = 'U';
                sres = rsres + lsres;
            }
            return (lres|rres);
        }
    }
    return (res|lres|rres);
}

class Solution {
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string res;
        dfs(res, root, startValue, destValue);
        return res;
    }
};
