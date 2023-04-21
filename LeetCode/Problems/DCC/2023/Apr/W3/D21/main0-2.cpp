// 自力AC2

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll mod = (ll)(1e9) + 7;
class Solution {
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        int m = group.size();
        vector<vector<vector<ll>>> memo(m+1, vector<vector<ll>>(n+1, vector<ll>(minProfit+1, -1)));
        auto dfs = [&](auto& dfs, int mi, int ni, int pi) -> ll {
            if (memo[mi][ni][pi] != -1) return memo[mi][ni][pi];
            if (mi-1 < 0) return memo[mi][ni][pi] = (ni==0 && pi==0) ? 1 : 0;
            ll val = dfs(dfs, mi-1, ni, pi);
            if (ni-group[mi-1] >= 0) {
                if (pi == minProfit) for (int i=0; i<=profit[mi-1]&&pi-i>=0; ++i) val = (val + dfs(dfs, mi-1, ni-group[mi-1], pi-i)) % mod;
                else if (pi-profit[mi-1] >= 0) val = (val + dfs(dfs, mi-1, ni-group[mi-1], pi-profit[mi-1])) % mod;
            }
            return memo[mi][ni][pi] = val;
        };
        ll res = 0;
        for (int i=0; i<=n; ++i) res = (res + dfs(dfs, m, i, minProfit)) % mod;
        return (int)res;
    }
};
