#include <bits/stdc++.h>
using namespace std;

// 自力AC1

class Solution {
    int INF = (int)(1e9);
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) return 0;
        vector<vector<int>> dp(n+1, vector<int>(2, -INF));
        dp[0][0] = 0;
        for (int i=1; i<n+1; ++i) {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
            for (int j=0; j<i-1; ++j) dp[i][1] = max(dp[i][1], dp[j][0]+(prices[i-1]-prices[j]));
        }
        return max(dp[n][0], dp[n][1]);
    }
};
