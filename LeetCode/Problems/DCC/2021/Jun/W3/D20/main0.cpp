#include <bits/stdc++.h>
using namespace std;

// 自力AC

const int INF = (int)(1e9);
const vector<int> dy = { -1, 0, 1, 0 }, dx = { 0, 1, 0, -1 };
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n, INF));
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> que;
        dist[0][0] = grid[0][0];
        que.emplace(grid[0][0], 0, 0);
        while (!que.empty()) {
            auto [d, y, x] = que.top(); que.pop();
            for (int i=0; i<4; ++i) {
                int ny = y + dy[i], nx = x + dx[i];
                if (ny<0 || ny>=n || nx<0 || nx>=n) continue;
                int nd = max(d, grid[ny][nx]);
                if (dist[ny][nx] <= nd) continue;
                dist[ny][nx] = nd;
                que.emplace(nd, ny, nx);
            }
        }
        return dist[n-1][n-1];
    }
};
