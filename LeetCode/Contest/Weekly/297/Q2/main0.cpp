// 本番AC

#include <bits/stdc++.h>
using namespace std;

const int INF = (int)(1e9);
class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int m = grid.size(), n = grid.front().size();
        vector<vector<int>> dp(m, vector<int>(n, INF));
        for (int i=0; i<n; ++i) dp[0][i] = grid[0][i];
        for (int i=0; i<m-1; ++i) for (int j=0; j<n; ++j) for (int i2=0; i2<n; ++i2) 
            dp[i+1][i2] = min(dp[i+1][i2], dp[i][j]+moveCost[grid[i][j]][i2]+grid[i+1][i2]);
        int res = INF;
        for (int i=0; i<n; ++i) res = min(res, dp[m-1][i]);
        return res;
    }
};
