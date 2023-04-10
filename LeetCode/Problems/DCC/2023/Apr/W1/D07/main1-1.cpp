// 解説AC1

#include <bits/stdc++.h>
using namespace std;

const vector<int> dy = { -1, 0, 1, 0 }, dx = { 0, 1, 0, -1 };
class Solution {
    void dfs(vector<vector<int>>& grid, int m, int n, int yi, int xi) {
        if (yi<0 || yi>=m || xi<0 || xi>=n || grid[yi][xi]!=1) return;
        grid[yi][xi] = -1;
        for (int i=0; i<4; ++i) dfs(grid, m, n, yi+dy[i], xi+dx[i]);
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid.front().size();
        for (int i=0; i<m; ++i) {
            dfs(grid, m, n, i, 0);
            dfs(grid, m, n, i, n-1);
        }
        for (int i=0; i<n; ++i) {
            dfs(grid, m, n, 0, i);
            dfs(grid, m, n, m-1, i);
        }
        int res = 0;
        for (int i=0; i<m; ++i) res += count(grid[i].begin(), grid[i].end(), 1);
        return res;
    }
};
