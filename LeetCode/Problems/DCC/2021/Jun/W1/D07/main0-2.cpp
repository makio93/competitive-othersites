#include <bits/stdc++.h>
using namespace std;

// 自力AC2,空間計算量を削減

const int INF = (int)(1e9);
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(3, INF);
        dp[0] = dp[1] = 0;
        for (int i=0; i<n; ++i) {
            dp[(i+1)%3] = min(dp[(i+1)%3], dp[i%3]+cost[i]);
            if (i+2 <= n) {
                dp[(i+2)%3] = INF;
                dp[(i+2)%3] = min(dp[(i+2)%3], dp[i%3]+cost[i]);
            }
        }
        return dp[n%3];
    }
};
