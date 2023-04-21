// 解説AC1

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
            if (mi == m) return memo[mi][ni][pi] = (pi == minProfit) ? 1 : 0;
            ll val = dfs(dfs, mi+1, ni, pi);
            if (ni+group[mi] <= n) val += dfs(dfs, mi+1, ni+group[mi], min(minProfit, pi+profit[mi]));
            return memo[mi][ni][pi] = val % mod;
        };
        return (int)dfs(dfs, 0, 0, 0);
    }
};
