#include <bits/stdc++.h>
using namespace std;

// 解説AC2

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.length(), m = word2.length();
        if (n < m) {
            swap(word1, word2);
            swap(n, m);
        }
        vector<vector<int>> dp(2, vector<int>(m+1));
        for (int i=0; i<=n; ++i) for (int j=0; j<=m; ++j) {
            if (i==0 || j==0) {
                if (i == 0) dp[i%2][j] = j;
                else dp[i%2][j] = i;
            }
            else if (word1[i-1] == word2[j-1]) dp[i%2][j] = dp[(i-1)%2][j-1];
            else dp[i%2][j] = min(dp[(i-1)%2][j], dp[i%2][j-1]) + 1;
        }
        return dp[n%2][m];
    }
};
