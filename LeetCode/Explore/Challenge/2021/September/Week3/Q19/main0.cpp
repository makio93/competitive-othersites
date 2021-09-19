#include <bits/stdc++.h>
using namespace std;

// 自力AC

using ull = unsigned long long;
class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.length(), m = t.length();
        vector<vector<ull>> dp(n+1, vector<ull>(m+1));
        for (int i=0; i<=n; ++i) dp[i][0] = 1;
        for (int i=0; i<n; ++i) for (int j=0; j<m; ++j) {
            if (s[i] == t[j]) dp[i+1][j+1] += dp[i][j];
            dp[i+1][j+1] += dp[i][j+1];
        }
        return (int)dp[n][m];
    }
};
