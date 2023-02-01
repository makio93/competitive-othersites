// 本番AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid.front().size();
        for (int i=0; i<m; ++i) sort(grid[i].begin(), grid[i].end());
        int res = 0;
        for (int i=n-1; i>=0; --i) {
            int mval = 0;
            for (int j=0; j<m; ++j) mval = max(mval, grid[j][i]);
            res += mval;
        }
        return res;
    }
};
