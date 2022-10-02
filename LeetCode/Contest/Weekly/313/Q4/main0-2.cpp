// 本番AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
class Solution {
    const ll mod = (ll)(1e16) + 7;
    const int INF = (int)(1e9);
public:
    int deleteString(string s) {
        int n = s.length();
        vector<vector<ll>> hvals(n+1, vector<ll>(n+1));
        for (int i=0; i<n; ++i) {
            ll hval = 0;
            for (int j=i; j<n; ++j) {
                hval = (hval * 27 + (int)(s[j]-'a'+1)) % mod;
                hvals[i][j+1] = hval;
            }
        }
        vector<int> dp(n+1, -INF);
        dp[0] = 0;
        for (int i=1; i<=n; ++i) {
            for (int j=1; j<=n; ++j) {
                if (i-j<0 || i+j>n) break;
                if (hvals[i-j][i]==hvals[i][i+j] && dp[i-j]!=-INF) dp[i] = max(dp[i], dp[i-j]+1);
            }
        }
        for (int i=0; i<n; ++i) if (dp[i] != -INF) dp[n] = max(dp[n], dp[i]+1);
        return dp[n];
    }
};
