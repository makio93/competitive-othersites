// 学習1回目,自力AC1

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n));
        for (int i=0; i<n; ++i) dp[i][i] = 1;
        for (int i=0; i<n; ++i) for (int j=i-1; j>=0; --j) {
            if (s[j] == s[i]) dp[j][i] = max(dp[j][i], dp[j+1][i-1]+2);
            dp[j][i] = max({ dp[j][i], dp[j+1][i], dp[j][i-1] });
        }
        return dp[0][n-1];
    }
};
