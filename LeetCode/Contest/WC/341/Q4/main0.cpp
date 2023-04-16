// 本番AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips) {
        int m = trips.size();
        vector<vector<int>> g(n);
        for (int i=0; i<n-1; ++i) {
            g[edges[i][0]].push_back(edges[i][1]);
            g[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> dep(n, -1), par(n, -1);
        function<void(int,int,int)> dfs0 = [&](int vi, int pi, int di) {
            dep[vi] = di;
            par[vi] = pi;
            for (const int& ti : g[vi]) if (ti != pi) dfs0(ti, vi, di+1);
        };
        dfs0(0, -1, 0);
        vector<int> vals(n);
        function<void(int,int)> add = [&](int vi, int mul) {
            vals[vi] += price[vi] * mul;
            if (par[vi] != -1) add(par[vi], mul);
        };
        function<int(int,int)> lca = [&](int ai, int bi) {
            if (dep[ai] > dep[bi]) swap(ai, bi);
            while (dep[ai] < dep[bi]) bi = par[bi];
            while (ai != bi) {
                ai = par[ai];
                bi = par[bi];
            }
            return ai;
        };
        for (int i=0; i<m; ++i) {
            add(trips[i][0], 1);
            add(trips[i][1], 1);
            int ci = lca(trips[i][0], trips[i][1]);
            add(ci, -2);
            vals[ci] += price[ci];
        }
        vector<vector<int>> dp(n, vector<int>(2));
        function<void(int,int)> dfs1 = [&](int vi, int pi) {
            for (const int& ti : g[vi]) if (ti != pi) {
                dfs1(ti, vi);
                dp[vi][0] += max(dp[ti][0], dp[ti][1]);
                dp[vi][1] += dp[ti][0];
            }
            dp[vi][1] += vals[vi];
        };
        dfs1(0, -1);
        int sub = max(dp[0][0], dp[0][1]) / 2, sum = accumulate(vals.begin(), vals.end(), 0);
        return sum - sub;
    }
};
