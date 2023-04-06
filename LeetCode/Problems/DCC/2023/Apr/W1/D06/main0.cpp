// 自力AC

#include <bits/stdc++.h>
using namespace std;

const vector<int> di = { -1, 0, 1, 0 }, dj = { 0, 1, 0, -1 };
class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid.front().size();
        vector visited(n, vector(m, false));
        queue<pair<int, int>> que;
        int res = 0;
        for (int i=0; i<n; ++i) for (int j=0; j<m; ++j) if (grid[i][j]==0 && !visited[i][j]) {
            bool wall = (i==0 || i==n-1 || j==0 || j==m-1);
            visited[i][j] = true;
            que.emplace(i, j);
            while (!que.empty()) {
                auto [vi, vj] = que.front(); que.pop();
                if (vi==0 || vi==n-1 || vj==0 || vj==m-1) wall = true;
                for (int i2=0; i2<4; ++i2) {
                    int ni = vi + di[i2], nj = vj + dj[i2];
                    if (ni<0 || ni>=n || nj<0 || nj>=m || grid[ni][nj]==1 || visited[ni][nj]) continue;
                    visited[ni][nj] = true;
                    que.emplace(ni, nj);
                }
            }
            if (!wall) ++res;
        }
        return res;
    }
};
