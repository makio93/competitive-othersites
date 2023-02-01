// 本番AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int n = nums.size(), m = multipliers.size();
        vector<vector<long long>> dp(m+1, vector<long long>(m+1, (long long)(-1e18)));
        dp[0] = vector<long long>(m+1);
        for (int i=1; i<=m; ++i) for (int j=0; j<=i; ++j) {
            if (j-1 >= 0) dp[i][j] = max(dp[i][j], dp[i-1][j-1]+nums[j-1]*multipliers[i-1]);
            if (j < i) dp[i][j] = max(dp[i][j], dp[i-1][j]+nums[(n-1)-(i-j-1)]*multipliers[i-1]);
        }
        long long mval = (long long)(-1e18);
        for (int i=0; i<=m; ++i) mval = max(mval, dp[m][i]);
        return mval;
    }
};
