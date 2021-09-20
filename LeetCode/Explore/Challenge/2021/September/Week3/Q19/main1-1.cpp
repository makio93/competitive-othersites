#include <bits/stdc++.h>
using namespace std;

// 解説AC1

using ll = long long;
const ll mod = (ll)(1e9) + 7;
class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.length(), m = t.length();
        vector<vector<ll>> dp(n+1, vector<ll>(m+1));
        for (int i=0; i<=n; ++i) dp[i][0] = 1;
        for (int i=0; i<n; ++i) for (int j=0; j<m; ++j) {
            if (s[i] == t[j]) dp[i+1][j+1] = (dp[i+1][j+1] + dp[i][j]) % mod;
            dp[i+1][j+1] = (dp[i+1][j+1] + dp[i][j+1]) % mod;
        }
        return dp[n][m];
    }
};
