// 本番AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
class Solution {
public:
    long long maxOutput(int n, vector<vector<int>>& edges, vector<int>& price) {
        vector<vector<int>> g(n);
        for (int i=0; i<n-1; ++i) {
            g[edges[i][0]].push_back(edges[i][1]);
            g[edges[i][1]].push_back(edges[i][0]);
        }
        vector<ll> vals(n);
        auto dfs0 = [&](auto dfs0, int vi=0, int pi=-1) -> void {
            for (const int& ti : g[vi]) if (ti != pi) {
                dfs0(dfs0, ti, vi);
                vals[vi] = max(vals[vi], vals[ti]);
            }
            vals[vi] += price[vi];
        };
        dfs0(dfs0);
        auto dfs1 = [&](auto dfs1, int vi=0, int pi=-1, ll mval=0) -> ll {
            ll nval = mval;
            if ((pi==-1&&g[vi].empty()) || (pi!=-1&&(int)(g[vi].size())==1)) return max(nval, vals[vi]-price[vi]);
            vector<pair<ll, int>> clst;
            for (const int& ti : g[vi]) if (ti != pi) clst.emplace_back(vals[ti], ti);
            clst.emplace_back(0, n);
            sort(clst.rbegin(), clst.rend());
            for (const int& ti : g[vi]) if (ti != pi) {
                ll tval = mval + price[vi];
                if (clst[0].second == ti) tval = max(tval, clst[1].first+price[vi]);
                else tval = max(tval, clst[0].first+price[vi]);
                nval = max(nval, dfs1(dfs1, ti, vi, tval));
            }
            return max(nval, vals[vi]-price[vi]);
        };
        return dfs1(dfs1);
    }
};
