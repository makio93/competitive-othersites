// 本番AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll mod = (ll)(1e9) + 7;
class Solution {
public:
    int countPaths(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid.front().size();
        vector<vector<ll>> memo(m, vector<ll>(n, -1));
        auto dfs = [&](auto dfs, int y, int x) -> ll {
            if (memo[y][x] != -1) return memo[y][x];
            ll rval = 1;
            const vector<int> dy = { -1, 0, 1, 0 }, dx = { 0, 1, 0, -1 };
            for (int i1=0; i1<4; ++i1) {
                int ny = y + dy[i1], nx = x + dx[i1];
                if (ny<0 || ny>=m || nx<0 || nx>=n || grid[ny][nx]<=grid[y][x]) continue;
                rval = (rval + dfs(dfs, ny, nx)) % mod;
            }
            return memo[y][x] = rval;
        };
        ll res = 0;
        for (int i=0; i<m; ++i) for (int j=0; j<n; ++j) res = (res + dfs(dfs, i, j)) % mod;
        return (int)res;
    }
};
