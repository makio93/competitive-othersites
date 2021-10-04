#include <bits/stdc++.h>
using namespace std;

// 自力AC

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid.front().size();
        vector<vector<int>> rsub(n, vector<int>(m+1)), csub(m, vector<int>(n+1));
        for (int i=0; i<n; ++i) {
            rsub[i][0] = grid[i][0];
            for (int j=1; j<m; ++j) rsub[i][j] = abs(grid[i][j] - grid[i][j-1]);
            rsub[i][m] = grid[i][m-1];
        }
        for (int i=0; i<m; ++i) {
            csub[i][0] = grid[0][i];
            for (int j=1; j<n; ++j) csub[i][j] = abs(grid[j][i] - grid[j-1][i]);
            csub[i][n] = grid[n-1][i];
        }
        int res = 0;
        for (int i=0; i<n; ++i) for (int j=0; j<m+1; ++j) res += abs(rsub[i][j]);
        for (int i=0; i<m; ++i) for (int j=0; j<n+1; ++j) res += abs(csub[i][j]);
        return res;
    }
};
