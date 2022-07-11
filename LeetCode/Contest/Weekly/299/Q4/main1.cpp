// 解説AC

#include <bits/stdc++.h>
using namespace std;

const int INF = (int)(1e9);
class Solution {
public:
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<int> xvals(n), vlst, ptmp;
        vector<vector<bool>> childs(n, vector<bool>(n));
        vector<vector<int>> g(n);
        for (int i=0; i<n-1; ++i) {
            g[edges[i][0]].push_back(edges[i][1]);
            g[edges[i][1]].push_back(edges[i][0]);
        }
        auto dfs = [&](auto dfs, int vi=0, int pi=-1) -> int {
            int xval = nums[vi];
            vlst.push_back(vi);
            for (int pv : ptmp) childs[pv][vi] = true;
            ptmp.push_back(vi);
            for (int ti : g[vi]) if (ti != pi) xval ^= dfs(dfs, ti, vi);
            ptmp.pop_back();
            return xvals[vi] = xval;
        };
        dfs(dfs);
        int res = INF;
        for (int i=1; i<n; ++i) for (int j=i+1; j<n; ++j) {
            int ax = xvals[vlst[i]], bx = xvals[vlst[j]], cx = xvals[vlst[0]];
            if (childs[vlst[i]][vlst[j]]) cx ^= ax, ax ^= bx;
            else cx ^= ax, cx ^= bx;
            res = min(res, max({ax,bx,cx})-min({ax,bx,cx}));
        }
        return res;
    }
};
