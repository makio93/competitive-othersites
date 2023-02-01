// 自力AC

#include <bits/stdc++.h>
using namespace std;

const int INF = (int)(1e9);
const vector<int> dy = { -1, 0, 1, 0 }, dx = { 0, 1, 0, -1 };
class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid.front().size();
        vector<vector<int>> dist(m, vector<int>(n, INF));
        deque<pair<int, int>> deq;
        dist[0][0] = 0;
        deq.emplace_back(0, 0);
        while (!deq.empty()) {
            auto pi = deq.front(); deq.pop_front();
            int y = pi.first, x = pi.second, di = dist[y][x];
            for (int i=0; i<4; ++i) {
                int ny = y + dy[i], nx = x + dx[i];
                if (ny<0 || ny>=m || nx<0 || nx>=n) continue;
                int ndi = di + grid[ny][nx];
                if (dist[ny][nx] <= ndi) continue;
                dist[ny][nx] = ndi;
                if (grid[ny][nx] == 1) deq.emplace_back(ny, nx);
                else deq.emplace_front(ny, nx);
            }
        }
        return dist[m-1][n-1];
    }
};
