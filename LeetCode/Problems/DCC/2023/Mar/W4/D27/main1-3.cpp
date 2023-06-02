// 解説AC3

#include <bits/stdc++.h>
using namespace std;

const int INF = (int)(1e9);
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid.front().size();
        vector<int> dp(n, INF);
        dp[0] = 0;
        for (int i=0; i<m; ++i) for (int j=0; j<n; ++j) {
            if (j == 0) dp[j] = dp[j] + grid[i][j];
            else dp[j] = min(dp[j], dp[j-1]) + grid[i][j];
        }
        return dp[n-1];
    }
};
