// 解説AC1

#include <bits/stdc++.h>
using namespace std;

const vector<int> di = { -1, 0, 1, 0 }, dj = { 0, 1, 0, -1 };
class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid.front().size();
        vector visited(n, vector(m, false));
        queue<pair<int, int>> que;
        auto bfs = [&](int si, int sj) -> bool {
            que = {};
            bool wall = false;
            visited[si][sj] = true;
            que.emplace(si, sj);
            while (!que.empty()) {
                auto [vi, vj] = que.front(); que.pop();
                for (int i2=0; i2<4; ++i2) {
                    int ni = vi + di[i2], nj = vj + dj[i2];
                    if (ni<0 || ni>=n || nj<0 || nj>=m) {
                        wall = true;
                        continue;
                    }
                    if (grid[ni][nj]==1 || visited[ni][nj]) continue;
                    visited[ni][nj] = true;
                    que.emplace(ni, nj);
                }
            }
            return !wall;
        };
        int res = 0;
        for (int i=0; i<n; ++i) for (int j=0; j<m; ++j) if (grid[i][j]==0 && !visited[i][j] && bfs(i, j)) ++res; 
        return res;
    }
};
