#include <bits/stdc++.h>
using namespace std;

// 自力AC

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.length(), m = word2.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1));
        for (int i=0; i<n; ++i) for (int j=0; j<m; ++j) {
            if (word1[i] == word2[j]) dp[i+1][j+1] = dp[i][j] + 1;
            else dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
        }
        return (n+m) - dp[n][m] * 2;
    }
};
