// 解説AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isScramble(string s1, string s2) {
        int n = s1.length();
        vector dp(n, vector(n+1, vector(n, 0)));
        for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) dp[i][i+1][j] = s1[i] == s2[j];
        for (int k=2; k<=n; ++k) for (int i=0; i+k<=n; ++i) for (int j=0; j+k<=n; ++j) for (int l=1; l<k; ++l) {
            auto &dp1 = dp[i][i+l], &dp2 = dp[i+l][i+k];
            dp[i][i+k][j] |= (dp1[j]&&dp2[j+l]) || (dp1[j+k-l]&&dp2[j]);
        }
        return (bool)dp[0][n][0];
    }
};
