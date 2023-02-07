// 自力AC1

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid.front().size();
        int res = 0;
        for (int i=0; i<m; ++i) for (int j=0; j<n; ++j) if (grid[i][j] == 1) {
            int cnt = 0;
            static const array<int, 4> dy = { -1, 0, 1, 0 }, dx = { 0, 1, 0, -1 };
            queue<pair<int, int>> que;
            auto que_push = [&](int yi, int xi) -> void {
                if (yi<0 || yi>=m || xi<0 || xi>=n || grid[yi][xi]==0) return;
                que.emplace(yi, xi);
                grid[yi][xi] = 0;
                ++cnt;
            };
            que_push(i, j);
            while (!que.empty()) {
                auto pi = que.front(); que.pop();
                int y = pi.first, x = pi.second;
                for (int i2=0; i2<4; ++i2) que_push(y+dy[i2], x+dx[i2]);
            }
            res = max(res, cnt);
        }
        return res;
    }
};
