// 解説AC2

#include <bits/stdc++.h>
using namespace std;

class Solution {
    const int mod = (int)(1e9) + 7;
public:
    int kInversePairs(int n, int k) {
        vector<vector<int>> dp(n, vector<int>(k+1));
        dp[0][0] = 1;
        for (int i=1; i<n; ++i) for (int j=0; j<=k&&j<=i*(i+1)/2; ++j) {
            dp[i][j] = ((dp[i-1][j] - (j-i-1>=0 ? dp[i-1][j-i-1] : 0) + mod) % mod + (j-1>=0 ? dp[i][j-1] : 0)) % mod;
        }
        return dp[n-1][k];
    }
};
