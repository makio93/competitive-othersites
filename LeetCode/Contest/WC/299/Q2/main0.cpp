// 本番AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll mod = (ll)(1e9) + 7;
class Solution {
public:
    int countHousePlacements(int n) {
        vector<vector<ll>> dp(n+1, vector<ll>(4));
        dp[0][0] = 1;
        for (int i=0; i<n; ++i) {
            for (int j1=0; j1<4; ++j1) for (int j2=0; j2<4; ++j2) if ((j1&j2) == 0) {
                dp[i+1][j1] = (dp[i+1][j1] + dp[i][j2]) % mod;
            }
        }
        ll res = 0;
        for (int i=0; i<4; ++i) res = (res + dp[n][i]) % mod;
        return (int)res;
    }
};
