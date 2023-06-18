// 解説AC1

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const vector<int> di = { -1, 0, 1, 0 }, dj = { 0, 1, 0, -1 };
const ll mod = (ll)(1e9) + 7;
class Solution {
public:
    int countPaths(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid.front().size();
        vector<ll> dp(m*n, 1);
        vector<pair<int, int>> vlst;
        for (int i=0; i<m; ++i) for (int j=0; j<n; ++j) vlst.emplace_back(grid[i][j], i*n+j);
        sort(vlst.begin(), vlst.end());
        for (int i=0; i<m*n; ++i) {
            auto [val, id] = vlst[i];
            int vi = id / n, vj = id % n;
            for (int i2=0; i2<4; ++i2) {
                int ni = vi + di[i2], nj = vj + dj[i2];
                if (ni<0 || ni>=m || nj<0 || nj>=n || grid[ni][nj]<=val) continue;
                dp[ni*n+nj] = (dp[ni*n+nj] + dp[id]) % mod;
            }
        }
        ll res = 0;
        for (int i=0; i<m*n; ++i) res = (res + dp[i]) % mod;
        return (int)res;
    }
};
