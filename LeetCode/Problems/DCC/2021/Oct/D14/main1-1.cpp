#include <bits/stdc++.h>
using namespace std;

// 解説AC1,DP解法

class Solution {
    int INF = (int)(1e9);
public:
    int numSquares(int n) {
        if (n <= 0) return 0;
        vector<int> dp(n+1, INF);
        dp[0] = 0;
        for (int i=1; i<=n; ++i) for (int j=1; j*j<=i; ++j) dp[i] = min(dp[i], dp[i-j*j]+1);
        return dp[n];
    }
};
