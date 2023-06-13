// 自力AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length(), res = 1;
        vector<vector<int>> dp(n+1, vector<int>(n));
        for (int i=0; i<n; ++i) dp[1][i] = 1;
        for (int k=2; k<=n; ++k) for (int i=0; i+k-1<n; ++i) {
            dp[k][i] = max(dp[k-1][i], dp[k-1][i+1]);
            if (s[i] == s[i+k-1]) dp[k][i] = max(dp[k][i], dp[k-2][i+1]+2);
            res = max(res, dp[k][i]);
        }
        return res;
    }
};
