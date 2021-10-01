#include <bits/stdc++.h>
using namespace std;

// 自力AC

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length(), m = text2.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1));
        for (int i=0; i<n; ++i) for (int j=0; j<m; ++j) {
            dp[i+1][j+1] = max({dp[i+1][j+1], dp[i][j+1], dp[i+1][j]});
            if (text1[i] == text2[j]) dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j]+1);
        }
        return dp[n][m];
    }
};
