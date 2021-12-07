#include <bits/stdc++.h>
using namespace std;

// 解説AC1

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.length(), m = word2.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1));
        for (int i=0; i<n; ++i) dp[i+1][0] = i + 1;
        for (int j=0; j<m; ++j) dp[0][j+1] = j + 1;
        for (int i=0; i<n; ++i) for (int j=0; j<m; ++j) {
            if (word1[i] == word2[j]) dp[i+1][j+1] = dp[i][j];
            else dp[i+1][j+1] = min(dp[i][j+1], dp[i+1][j]) + 1;
        }
        return dp[n][m];
    }
};
