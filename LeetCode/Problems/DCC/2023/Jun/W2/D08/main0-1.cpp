// 自力AC1

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid.front().size(), res = 0;
        for (int i=0; i<m; ++i) for (int j=0; j<n; ++j) if (grid[i][j] < 0) ++res;
        return res;
    }
};
