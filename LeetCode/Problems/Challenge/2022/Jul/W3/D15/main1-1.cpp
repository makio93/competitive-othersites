// 

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid.front().size();
        vector<vector<bool>> visited(m, vector<bool>(n));
        int res = 0;
        auto dfs = [&](auto dfs, int y, int x) -> int {
            if (y<0 || y>=m || x<0 || x>=n || visited[y][x] || grid[y][x]==0) return 0;
            visited[y][x] = true;
            return 1 + dfs(dfs, y-1, x) + dfs(dfs, y, x+1) + dfs(dfs, y+1, x) + dfs(dfs, y, x-1);
        };
        for (int i=0; i<m; ++i) for (int j=0; j<n; ++j) res = max(res, dfs(dfs, i, j));
        return res;
    }
};
