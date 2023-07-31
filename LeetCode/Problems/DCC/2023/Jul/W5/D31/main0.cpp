// 自力AC

#include <bits/stdc++.h>
using namespace std;

const int INF = (int)(1e9);
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.length(), m = s2.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1, INF));
        for (int i=0; i<=n; ++i) for (int j=0; j<=m; ++j) {
            if (i == 0 && j == 0) dp[i][j] = 0;
            else if (i == 0) dp[i][j] = dp[i][j-1] + (int)s2[j-1];
            else if (j == 0) dp[i][j] = dp[i-1][j] + (int)s1[i-1];
            else {
                dp[i][j] = min(dp[i-1][j]+(int)s1[i-1], dp[i][j-1]+(int)s2[j-1]);
                if (s1[i-1] == s2[j-1]) dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
            }
        }
        return dp[n][m];
    }
};
