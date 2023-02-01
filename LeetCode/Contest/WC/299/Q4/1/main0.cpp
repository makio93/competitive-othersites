// 学習1回目,自力AC

#include <bits/stdc++.h>
using namespace std;

const int INF = (int)(1e9);
class Solution {
    int n;
    vector<vector<int>> g;
    vector<int> nums, xvals;
    void dfs0(int vi, int pi) {
        xvals[vi] = nums[vi];
        for (const int& ti : g[vi]) if (ti != pi) {
            dfs0(ti, vi);
            xvals[vi] ^= xvals[ti];
        }
    }
    int dfs1(int vi, int pi, int xval, int sval) {
        int res = INF;
        for (const int& ti : g[vi]) if (ti != pi) {
            res = min(res, dfs1(ti, vi, xval, sval));
            int aval = xvals[ti], bval = xval ^ aval;
            res = min(res, max({sval,aval,bval})-min({sval,aval,bval}));
        }
        return res;
    }
public:
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        n = nums.size();
        this->nums = nums;
        int res = INF;
        g.assign(n, vector<int>(0));
        for (int i=0; i<n-1; ++i) {
            g[edges[i][0]].push_back(edges[i][1]);
            g[edges[i][1]].push_back(edges[i][0]);
        }
        for (int i=0; i<n-1; ++i) {
            xvals.assign(n, 0);
            dfs0(edges[i][0], edges[i][1]);
            dfs0(edges[i][1], edges[i][0]);
            res = min(res, dfs1(edges[i][0], edges[i][1], xvals[edges[i][0]], xvals[edges[i][1]]));
            res = min(res, dfs1(edges[i][1], edges[i][0], xvals[edges[i][1]], xvals[edges[i][0]]));
        }
        return res;
    }
};
