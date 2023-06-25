// 学習1回目,自力AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll mod = (ll)(1e9) + 7;
const vector<int> dr = { -1, 0, 1, 0 }, dc = { 0, 1, 0, -1 };
class Solution {
public:
    int countPaths(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid.front().size();
        vector<vector<ll>> memo(m, vector<ll>(n, -1));
        function<ll(int,int)> f = [&](int ri, int ci) {
            if (memo[ri][ci] != -1) return memo[ri][ci];
            ll rval = 1;
            for (int i2=0; i2<4; ++i2) {
                int nri = ri + dr[i2], nci = ci + dc[i2];
                if (nri<0 || nri>=m || nci<0 || nci>=n || grid[nri][nci]<=grid[ri][ci]) continue;
                rval = (rval + f(nri, nci)) % mod;
            }
            return memo[ri][ci] = rval;
        };
        ll res = 0;
        for (int i=0; i<m; ++i) for (int j=0; j<n; ++j) res = (res + f(i, j)) % mod;
        return (int)res;
    }
};
