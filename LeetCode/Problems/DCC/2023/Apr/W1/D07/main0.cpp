// 自力AC

#include <bits/stdc++.h>
using namespace std;

const vector<int> dy = { -1, 0, 1, 0 }, dx = { 0, 1, 0, -1 };
class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid.front().size();
        queue<pair<int, int>> que;
        for (int i=0; i<m; ++i) for (int j=0; j<n; ++j) if ((i==0 || i==m-1 || j==0 || j==n-1) && grid[i][j]==1) {
            que.emplace(i, j);
            grid[i][j] = -1;
        }
        while (!que.empty()) {
            auto [yi, xi] = que.front(); que.pop();
            for (int i=0; i<4; ++i) {
                int nyi = yi + dy[i], nxi = xi + dx[i];
                if (nyi<0 || nyi>=m || nxi<0 || nxi>=n || grid[nyi][nxi]!=1) continue;
                grid[nyi][nxi] = -1;
                que.emplace(nyi, nxi);
            }
        }
        int res = 0;
        for (int i=0; i<m; ++i) res += count(grid[i].begin(), grid[i].end(), 1);
        return res;
    }
};
