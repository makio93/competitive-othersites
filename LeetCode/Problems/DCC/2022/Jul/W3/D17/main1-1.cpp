// 解説AC1(累積和を計算))

#include <bits/stdc++.h>
using namespace std;

class Solution {
    const int mod = (int)(1e9) + 7;
public:
    int kInversePairs(int n, int k) {
        vector<vector<int>> dp(n+1, vector<int>(k+1));
        for (int i=1; i<=n; ++i) for (int j=0; j<=k; ++j) {
            if (i==1 && j==0) {
                dp[i][j] = 1;
                continue;
            }
            dp[i][j] = ((dp[i-1][j] - (j-i>=0 ? dp[i-1][j-i] : 0) + mod) % mod + (j-1>=0 ? dp[i][j-1] : 0)) % mod;
        }
        return (dp[n][k] - (k-1>=0 ? dp[n][k-1] : 0) + mod) % mod;
    }
};
