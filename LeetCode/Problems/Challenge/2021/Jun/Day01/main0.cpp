#include <bits/stdc++.h>
using namespace std;

// 自力AC

const vector<int> dy = { -1, 0, 1, 0 }, dx = { 0, 1, 0, -1 };
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid.front().size();
        int res = 0;
        for (int i=0; i<m; ++i) for (int j=0; j<n; ++j) if (grid[i][j] == 1) {
            queue<pair<int, int>> que;
            int mcnt = 1;
            grid[i][j] *= -1;
            que.emplace(i, j);
            while (!que.empty()) {
                auto [y, x] = que.front(); que.pop();
                for (int i2=0; i2<4; ++i2) {
                    int ny = y + dy[i2], nx = x + dx[i2];
                    if (ny<0 || ny>=m || nx<0 || nx>=n) continue;
                    if (grid[ny][nx] != 1) continue;
                    grid[ny][nx] *= -1;
                    ++mcnt;
                    que.emplace(ny, nx);
                }
            }
            res = max(res, mcnt);
        }
        return res;
    }
};
