#include <bits/stdc++.h>
using namespace std;

// 自力AC

const int INF = (int)(1e9);
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1, INF);
        dp[0] = dp[1] = 0;
        for (int i=0; i<n; ++i) {
            dp[i+1] = min(dp[i+1], dp[i]+cost[i]);
            if (i+2 <= n) dp[i+2] = min(dp[i+2], dp[i]+cost[i]);
        }
        return dp[n];
    }
};
