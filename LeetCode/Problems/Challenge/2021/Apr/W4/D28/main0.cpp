#include <bits/stdc++.h>
using namespace std;

// 自力AC

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid.front().size();
        vector<vector<int>> dp(m+1, vector<int>(n+1));
        dp[1][1] = (obstacleGrid[0][0] == 0) ? 1 : 0;
        for (int i=1; i<=m; ++i) for (int j=1; j<=n; ++j) if (obstacleGrid[i-1][j-1] == 0) dp[i][j] += dp[i-1][j] + dp[i][j-1];
        return dp[m][n];
    }
};
