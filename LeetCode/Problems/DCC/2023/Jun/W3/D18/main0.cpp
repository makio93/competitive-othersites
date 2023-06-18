// 自力AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const vector<int> di = { -1, 0, 1, 0 }, dj = { 0, 1, 0, -1 };
const ll mod = (ll)(1e9) + 7;
class Solution {
public:
    int countPaths(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid.front().size();
        vector<vector<int>> rg(m*n);
        vector<int> din(m*n);
        for (int i=0; i<m; ++i) for (int j=0; j<n; ++j) for (int i2=0; i2<4; ++i2) {
            int ni = i + di[i2], nj = j + dj[i2];
            if (ni<0 || ni>=m || nj<0 || nj>=n || grid[ni][nj]>=grid[i][j]) continue;
            rg[i*n+j].push_back(ni*n+nj);
            din[ni*n+nj]++;
        }
        vector<ll> dp(m*n);
        queue<int> que;
        for (int i=0; i<m*n; ++i) if (din[i] == 0) {
            que.push(i);
            dp[i]++;
        }
        while (!que.empty()) {
            int vi = que.front(); que.pop();
            ll val = dp[vi];
            for (const int& ti : rg[vi]) if (din[ti] > 0) {
                din[ti]--;
                dp[ti] = (dp[ti] + val) % mod;
                if (din[ti] == 0) {
                    que.push(ti);
                    dp[ti] = (dp[ti] + 1) % mod;
                }
            }
        }
        ll res = 0;
        for (int i=0; i<m*n; ++i) res = (res + dp[i]) % mod;
        return (int)res;
    }
};
