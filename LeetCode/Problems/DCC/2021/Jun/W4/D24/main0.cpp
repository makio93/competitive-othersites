#include <bits/stdc++.h>
using namespace std;

// 自力AC

using ll = long long;
const ll mod = (ll)(1e9) + 7;
class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<bool>>> visited(m, vector<vector<bool>>(n, vector<bool>(maxMove+1)));
        vector<vector<vector<ll>>> dp(m, vector<vector<ll>>(n, vector<ll>(maxMove+1)));
        queue<tuple<int, int, int>> que;
        ll res = 0;
        visited[startRow][startColumn][0] = true;
        dp[startRow][startColumn][0] = 1;
        que.emplace(startRow, startColumn, 0);
        while (!que.empty()) {
            auto [y, x, d] = que.front(); que.pop();
            vector<int> dy = { -1, 0, 1, 0 }, dx = { 0, 1, 0, -1 };
            if (d+1 > maxMove) continue;
            for (int i=0; i<4; ++i) {
                int ny = y + dy[i], nx = x + dx[i];
                if (ny<0 || ny>=m || nx<0 || nx>=n) {
                    res = (res + dp[y][x][d]) % mod;
                    continue;
                }
                dp[ny][nx][d+1] = (dp[ny][nx][d+1] + dp[y][x][d]) % mod;
                if (!visited[ny][nx][d+1]) {
                    visited[ny][nx][d+1] = true;
                    que.emplace(ny, nx, d+1);
                }
            }
        }
        return (int)res;
    }
};
