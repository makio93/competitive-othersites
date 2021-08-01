#include <bits/stdc++.h>
using namespace std;

// 本番AC

class Solution {
    const int mod = (int)(1e9) + 7;
public:
    int countSpecialSubsequences(vector<int>& nums) {
        int n = nums.size();
        vector<vector<long long>> dp(n+1, vector<long long>(3));
        for (int i=1; i<=n; ++i) for (int j=0; j<3; ++j) {
            if (nums[i-1] == j) {
                if (j-1 >= 0) dp[i][j] = (dp[i][j] + dp[i-1][j-1]) % mod;
                else dp[i][j] = (dp[i][j] + 1) % mod;
                dp[i][j] = (dp[i][j] + dp[i-1][j]) % mod;
            }
            dp[i][j] = (dp[i][j] + dp[i-1][j]) % mod;
        }
        return (int)(dp[n][2] % mod);
    }
};
