// 自力AC1

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size(), res = 0;
        for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) {
            bool ok = true;
            for (int k=0; k<n; ++k) if (grid[i][k] != grid[k][j]) ok = false;
            if (ok) ++res;
        }
        return res;
    }
};
