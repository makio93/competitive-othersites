// 学習1回目,自力AC

#include <bits/stdc++.h>
using namespace std;

const int INF = (int)(1e9);
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size(), m = days.back();
        vector<bool> travels(m+1);
        for (int i=0; i<n; ++i) travels[days[i]] = true;
        vector<int> dp(m+1, INF);
        dp[0] = 0;
        for (int i=0; i<m; ++i) {
            if (!travels[i+1]) dp[i+1] = min(dp[i+1], dp[i]);
            dp[i+1] = min(dp[i+1], dp[i]+costs[0]);
            dp[min(m, i+7)] = min(dp[min(m, i+7)], dp[i]+costs[1]);
            dp[min(m, i+30)] = min(dp[min(m, i+30)], dp[i]+costs[2]);
        }
        return dp[m];
    }
};
