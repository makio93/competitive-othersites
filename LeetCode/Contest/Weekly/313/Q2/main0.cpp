// 本番AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
    const vector<int> di = { 0, 0, 0, 1, 2, 2, 2 }, dj = { 0, 1, 2, 1, 0, 1, 2 };
public:
    int maxSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid.front().size(), res = 0;
        for (int i=0; i+2<m; ++i) for (int j=0; j+2<n; ++j) {
            int val = 0;
            for (int i2=0; i2<7; ++i2) val += grid[i+di[i2]][j+dj[i2]];
            res = max(res, val);
        }
        return res;
    }
};
