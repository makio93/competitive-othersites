// 自力AC

#include <bits/stdc++.h>
using namespace std;

const vector<int> dy = { -1, 0, 1, 0 }, dx = { 0, 1, 0, -1 };
const int INF = (int)(1e9);
class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size(), sy = -1, sx = -1;
        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) if (grid[i][j] == 1) {
                sy = i, sx = j;
                break;
            }
            if (sy != -1) break;
        }
        queue<pair<int, int>> que;
        que.emplace(sy, sx);
        grid[sy][sx] = 2;
        while (!que.empty()) {
            auto [yi, xi] = que.front(); que.pop();
            for (int i2=0; i2<4; ++i2) {
                int nyi = yi + dy[i2], nxi = xi + dx[i2];
                if (nyi<0 || nyi>=n || nxi<0 || nxi>=n || grid[nyi][nxi]!=1) continue;
                grid[nyi][nxi] = 2;
                que.emplace(nyi, nxi);
            }
        }
        vector<vector<int>> dist(n, vector<int>(n, INF));
        for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) if (grid[i][j] == 1) {
            que.emplace(i, j);
            dist[i][j] = 0;
        }
        while (!que.empty()) {
            auto [yi, xi] = que.front(); que.pop();
            int di = dist[yi][xi], ndi = di + 1;
            for (int i2=0; i2<4; ++i2) {
                int nyi = yi + dy[i2], nxi = xi + dx[i2];
                if (nyi<0 || nyi>=n || nxi<0 || nxi>=n || dist[nyi][nxi]<=ndi) continue;
                dist[nyi][nxi] = ndi;
                que.emplace(nyi, nxi);
            }
        }
        int res = INF;
        for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) if (grid[i][j] == 2) res = min(res, dist[i][j]);
        return res - 1;
    }
};
