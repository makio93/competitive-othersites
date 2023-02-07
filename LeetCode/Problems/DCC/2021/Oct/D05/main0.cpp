#include <bits/stdc++.h>
using namespace std;

// 自力AC1,Space:O(n)解

class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1);
        dp[0] = 1;
        for (int i=0; i<n; ++i) {
            dp[i+1] += dp[i];
            if (i+2 <= n) dp[i+2] += dp[i];
        }
        return dp[n];
    }
};
