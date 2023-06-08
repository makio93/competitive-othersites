// 自力AC2

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid.front().size(), res = 0, id = n;
        for (int i=0; i<m; ++i) {
            while (id-1>=0 && grid[i][id-1]<0) --id;
            res += n - id;
        }
        return res;
    }
};
