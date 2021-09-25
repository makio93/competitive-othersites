#include <bits/stdc++.h>
using namespace std;

// 自力AC

class Solution {
    int INF = (int)(1e9);
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid.front().size();
        vector<vector<vector<int>>> dist(n, vector<vector<int>>(m, vector<int>(k+1, INF)));
        queue<tuple<int, int, int>> que;
        que.emplace(0, 0, 0);
        dist[0][0][0] = 0;
        while (!que.empty()) {
            auto [yi, xi, ki] = que.front(); que.pop();
            int di = dist[yi][xi][ki], ndi = di + 1;
            vector<int> dy = { -1, 0, 1, 0 }, dx = { 0, 1, 0, -1 };
            for (int i=0; i<4; ++i) {
                int nyi = yi + dy[i], nxi = xi + dx[i];
                if (nyi<0 || nyi>=n || nxi<0 || nxi>=m) continue;
                int nki = ki + grid[nyi][nxi];
                if (nki > k) continue;
                if (dist[nyi][nxi][nki] <= ndi) continue;
                que.emplace(nyi, nxi, nki);
                dist[nyi][nxi][nki] = ndi;
            }
        }
        int res = INF;
        for (int i=0; i<=k; ++i) res = min(res, dist[n-1][m-1][i]);
        return (res == INF) ? -1 : res;
    }
};
