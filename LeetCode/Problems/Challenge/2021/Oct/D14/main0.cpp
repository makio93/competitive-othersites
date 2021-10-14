#include <bits/stdc++.h>
using namespace std;

// 自力AC1,DP

class Solution {
    int INF = (int)(1e9);
public:
    int numSquares(int n) {
        vector<int> dp(n+1, INF);
        dp[0] = 0;
        for (int i=1; i*i<=n; ++i) {
            for (int j=i*i; j<=n; ++j) {
                dp[j] = min(dp[j], dp[j-i*i]+1);
            }
        }
        return dp[n];
    }
};
