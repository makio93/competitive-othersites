// 自力AC1

#include <bits/stdc++.h>
using namespace std;

const int INF = (int)(1e9);
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size(), m = days[n-1];
        vector<bool> exists(m+31);
        for (int i=0; i<n; ++i) exists[days[i]] = true;
        vector<int> dp(m+31, INF);
        dp[0] = 0;
        for (int i=0; i<m; ++i) {
            if (exists[i+1]) dp[i+1] = min(dp[i+1], dp[i]+costs[0]);
            else dp[i+1] = min(dp[i+1], dp[i]);
            if (count(exists.begin()+i+1, exists.begin()+i+8, true)) dp[i+7] = min(dp[i+7], dp[i]+costs[1]);
            else dp[i+7] = min(dp[i+7], dp[i]);
            if (count(exists.begin()+i+1, exists.begin()+i+31, true)) dp[i+30] = min(dp[i+30], dp[i]+costs[2]);
            else dp[i+30] = min(dp[i+30], dp[i]);
        }
        return *min_element(dp.begin()+m, dp.end());
    }
};
