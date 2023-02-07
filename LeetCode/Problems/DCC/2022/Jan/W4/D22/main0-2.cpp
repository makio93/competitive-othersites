#include <bits/stdc++.h>
using namespace std;

// 自力AC,ヒントあり,DP解法

class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool> dp(n+1);
        for (int i=1; i<=n; ++i) for (int j=1; j*j<=i; ++j) {
            dp[i] = dp[i] | (!dp[i-j*j]);
            if (dp[i]) break;
        }
        return dp[n];
    }
};
