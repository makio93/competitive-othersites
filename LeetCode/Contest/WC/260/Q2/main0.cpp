#include <bits/stdc++.h>
using namespace std;

// 本番AC

using ll = long long;
class Solution {
    ll INF = (ll)(1e16);
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid.front().size();
        vector<ll> lsum(n+1), rsum(n+1);
        for (int i=0; i<n; ++i) lsum[i+1] = lsum[i] + grid[1][i];
        for (int i=n-1; i>=0; --i) rsum[i] = rsum[i+1] + grid[0][i];
        ll res = INF;
        for (int i=0; i<=n-1; ++i) res = min(res, max(lsum[i], rsum[i+1]));
        if (res == INF) res = 0;
        return res;
    }
};
