// 学習1回目,自力AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, n));
        for (int i=0; i<n; ++i) {
            dp[i][i] = 0;
            if (i-1 >= 0) dp[i][i-1] = 0;
        }
        for (int i=1; i<n; ++i) for (int j=0; j+i<n; ++j) {
            if (s[j] == s[j+i]) dp[j][j+i] = min(dp[j][j+i], dp[j+1][j+i-1]);
            dp[j][j+i] = min({ dp[j][j+i], dp[j][j+i-1]+1, dp[j+1][j+i]+1 });
        }
        return dp[0][n-1];
    }
};
