// 自力AC2

#include <bits/stdc++.h>
using namespace std;

const int INF = (int)(1e9);
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size(), m = days[n-1];
        vector<int> dsum(m+1);
        for (int i=0; i<n; ++i) dsum[days[i]] = 1;
        for (int i=0; i<m; ++i) dsum[i+1] += dsum[i];
        vector<int> dp(m+1, INF);
        dp[0] = 0;
        for (int i=0; i<m; ++i) {
            if (dsum[i+1]-dsum[i] > 0) dp[i+1] = min(dp[i+1], dp[i]+costs[0]);
            else dp[i+1] = min(dp[i+1], dp[i]);
            if (dsum[min(m, i+7)] - dsum[i] > 0) dp[min(m, i+7)] = min(dp[min(m, i+7)], dp[i]+costs[1]);
            else dp[min(m, i+7)] = min(dp[min(m, i+7)], dp[i]);
            if (dsum[min(m, i+30)] - dsum[i] > 0) dp[min(m, i+30)] = min(dp[min(m, i+30)], dp[i]+costs[2]);
            else dp[min(m, i+30)] = min(dp[min(m, i+30)], dp[i]);
        }
        return dp[m];
    }
};
