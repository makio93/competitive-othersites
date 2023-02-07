// 自力AC

#include <bits/stdc++.h>
using namespace std;

const int INF = (int)(1e9);
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n, INF));
        queue<int> que;
        if (grid[0][0] == 0) {    
            dist[0][0] = 1;
            que.push(0);
        }
        while (!que.empty()) {
            int vi = que.front(); que.pop();
            int y = vi / n, x = vi % n, di = dist[y][x], ndi = di + 1;
            for (int dy=-1; dy<=1; ++dy) for (int dx=-1; dx<=1; ++dx) if (dy!=0 || dx!=0) {
                int ny = y + dy, nx = x + dx;
                if (ny<0 || ny>=n || nx<0 || nx>=n || grid[ny][nx]!=0 || dist[ny][nx]<=ndi) continue;
                dist[ny][nx] = ndi;
                que.push(ny*n+nx);
            }
        }
        if (dist[n-1][n-1] == INF) return -1;
        else return dist[n-1][n-1];
    }
};
