#include <bits/stdc++.h>
using namespace std;

// 自力AC

const int INF = (int)(1e9);
class Solution {
    int zcnt = 0;
    vector<vector<int>> dist;
    int dfs(vector<vector<int>>& grid, int y, int x, int d=0) {
        if (grid[y][x] == 2) return (d==zcnt ? 1 : 0);
        else if (d > zcnt) return 0;
        else {
            int res = 0;
            const vector<int> dy = { -1, 0, 1, 0 }, dx = { 0, 1, 0, -1 };
            for (int i=0; i<4; ++i) {
                int ny = y + dy[i], nx = x + dx[i];
                if (ny<0 || ny>=(int)(grid.size()) || nx<0 || nx>=(int)(grid.front().size()) || grid[ny][nx]==-1 || dist[ny][nx]!=-1) continue;
                dist[ny][nx] = d + 1;
                res += dfs(grid, ny, nx, d+1);
                dist[ny][nx] = -1;
            }
            return res;
        }
    }
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid.front().size();
        int sy = -1, sx = -1;
        for (int i=0; i<m; ++i) for (int j=0; j<n; ++j) {
            if (grid[i][j] == 1) { sy = i; sx = j; }
            if (grid[i][j]==0 || grid[i][j]==2) ++zcnt;
        }
        dist = vector<vector<int>>(m, vector<int>(n, -1));
        dist[sy][sx] = 0;
        return dfs(grid, sy, sx);
    }
};
