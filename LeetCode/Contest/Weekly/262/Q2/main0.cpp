#include <bits/stdc++.h>
using namespace std;

// 本番AC

class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m = grid.size(), n = grid.front().size(), lval = (int)(1e9), rval = 0, res = 0;
        if (m*n == 1) return 0;
        for (int i=0; i<m; ++i) for (int j=0; j<n; ++j) {
            lval = min(lval, grid[i][j]);
            rval = max(rval, grid[i][j]);
        }
        for (int i=0; i<m; ++i) for (int j=0; j<n; ++j) if ((grid[i][j]-lval)%x != 0) return -1;
        vector<int> vals(m*n);
        for (int i=0; i<m; ++i) for (int j=0; j<n; ++j) vals[i*n+j] = grid[i][j];
        sort(vals.begin(), vals.end());
        int mval = vals[(m*n-1)/2];
        for (int i=0; i<m; ++i) for (int j=0; j<n; ++j) res += abs(grid[i][j]-mval) / x;
        if ((m*n)%2 == 1) {
            int mval2 = vals[(m*n-1)/2+1], res2 = 0;
            for (int i=0; i<m; ++i) for (int j=0; j<n; ++j) res2 += abs(grid[i][j]-mval2) / x;
            res = min(res, res2);
        }
        return res;
    }
};
