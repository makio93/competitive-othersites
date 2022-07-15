// 

#include <bits/stdc++.h>
using namespace std;

class Solution {
    const array<int, 4> dy = { -1, 0, 1, 0 }, dx = { 0, 1, 0, -1 };
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid.front().size();
        int res = 0;
        vector<vector<bool>> visited(m, vector<bool>(n));
        for (int i=0; i<m; ++i) for (int j=0; j<n; ++j) if (grid[i][j]==1 && !visited[i][j]) {
            int cnt = 0;
            stack<pair<int, int>> st;
            st.emplace(i, j);
            visited[i][j] = true;
            while (!st.empty()) {
                auto pi = st.top(); st.pop();
                int y = pi.first, x = pi.second;
                ++cnt;
                for (int i2=0; i2<4; ++i2) {
                    int ny = y + dy[i2], nx = x + dx[i2];
                    if (ny<0 || ny>=m || nx<0 || nx>=n || visited[ny][nx] || grid[ny][nx]==0) continue;
                    st.emplace(ny, nx);
                    visited[ny][nx] = true;
                }
            }
            res = max(res, cnt);
        }
        return res;
    }
};
