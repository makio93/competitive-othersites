#include <bits/stdc++.h>
using namespace std;

// 自力AC

class Solution {
    int INF = (int)(1e9);
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid.front().size();
        vector<vector<int>> dist(m, vector<int>(n, INF));
        queue<pair<int, int>> que;
        for (int i=0; i<m; ++i) for (int j=0; j<n; ++j) if (grid[i][j] == 2) {
            dist[i][j] = 0;
            que.emplace(i, j);
        }
        while (!que.empty()) {
            auto [y, x] = que.front(); que.pop();
            int d = dist[y][x], nd = d + 1;
            vector<int> dy = { -1, 0, 1, 0 }, dx = { 0, 1, 0, -1 };
            for (int i2=0; i2<4; ++i2) {
                int ny = y + dy[i2], nx = x + dx[i2];
                if (ny<0 || ny>=m || nx<0 || nx>=n) continue;
                if (grid[ny][nx] != 1) continue;
                if (dist[ny][nx] <= nd) continue;
                grid[ny][nx] = 2;
                dist[ny][nx] = nd;
                que.emplace(ny, nx);
            }
        }
        bool ok = true;
        for (int i=0; i<m; ++i) for (int j=0; j<n; ++j) if (grid[i][j] == 1) ok = false;
        if (!ok) return -1;
        else {
            int res = 0;
            for (int i=0; i<m; ++i) for (int j=0; j<n; ++j) if (dist[i][j] != INF) res = max(res, dist[i][j]);
            return res;
        }
    }
};
