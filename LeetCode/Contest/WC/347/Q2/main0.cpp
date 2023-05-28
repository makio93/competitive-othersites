// 本番AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid.front().size();
        function<int(int,int)> calc = [&](int syi, int sxi) {
            unordered_set<int> lst, rst;
            int yi = syi - 1, xi = sxi - 1;
            while (yi>=0 && xi>=0) {
                lst.insert(grid[yi][xi]);
                --yi; --xi;
            }
            yi = syi + 1, xi = sxi + 1;
            while (yi<m && xi<n) {
                rst.insert(grid[yi][xi]);
                ++yi; ++xi;
            }
            return abs((int)(lst.size()) - (int)(rst.size()));
        };
        vector<vector<int>> res(m, vector<int>(n));
        for (int i=0; i<m; ++i) for (int j=0; j<n; ++j) res[i][j] = calc(i, j);
        return res;
    }
};
