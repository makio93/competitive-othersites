// 解説AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int, int>> que;
        if (grid[0][0] == 0) {
            que.emplace(0, 0);
            grid[0][0] = 1;
        }
        while (!que.empty()) {
            auto pi = que.front(); que.pop();
            int y = pi.first, x = pi.second;
            if (y==n-1 && x==n-1) return grid[y][x];
            for (int dy=-1; dy<=1; ++dy) for (int dx=-1; dx<=1; ++dx) if (dy!=0 || dx!=0) {
                int ny = y + dy, nx = x + dx;
                if (ny<0 || ny>=n || nx<0 || nx>=n || grid[ny][nx]!=0) continue;
                que.emplace(ny, nx);
                grid[ny][nx] = grid[y][x] + 1;
            }
        }
        return -1;
    }
};
