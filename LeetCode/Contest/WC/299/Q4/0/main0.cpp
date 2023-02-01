// 本番終了後,自力AC

#include <bits/stdc++.h>
using namespace std;

const int INF = (int)(1e9);
class Solution {
public:
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<vector<int>> g(n);
        for (int i=0; i<n-1; ++i) {
            g[edges[i][0]].push_back(edges[i][1]);
            g[edges[i][1]].push_back(edges[i][0]);
        }
        auto bcalc = [&](auto bcalc, int pi, int vi) -> int {
            int val = nums[vi];
            for (int ti : g[vi]) if (pi != ti) val ^= bcalc(bcalc, vi, ti);
            return val;
        };
        int aval = bcalc(bcalc, -1, 0);
        int res = INF;
        for (int i=0; i<n-1; ++i) {
            int bval1 = bcalc(bcalc, edges[i][1], edges[i][0]);
            int bval2 = aval ^ bval1;
            auto dfs = [&](auto dfs, int pi, int vi, int tar, int sval) -> int {
                int val = nums[vi];
                for (int ti : g[vi]) if (ti != pi) {
                    int rval = dfs(dfs, vi, ti, tar, sval);
                    int tval = sval ^ rval;
                    res = min(res, max({tar,rval,tval})-min({tar,rval,tval}));
                    val ^= rval;
                }
                return val;
            };
            dfs(dfs, edges[i][0], edges[i][1], bval1, bval2);
            dfs(dfs, edges[i][1], edges[i][0], bval2, bval1);
        }
        return res;
    }
};
