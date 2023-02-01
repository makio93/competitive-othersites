#include <bits/stdc++.h>
using namespace std;

// 本番WA

using ll = long long;
class Solution {
    const ll mod = (ll)(1e9) + 7;
public:
    int colorTheGrid(int m, int n) {
        vector<vector<vector<ll>>> dp(m, vector<vector<ll>>(n, vector<ll>(3)));
        for (int i=0; i<m; ++i) for (int j=0; j<n; ++j) for (int i2=0; i2<3; ++i2) {
            ll uval = 0, lval = 0;
            if (i-1 >= 0) { for (int j2=0; j2<3; ++j2) if (j2 != i2) uval = (uval + dp[i-1][j][j2]) % mod; }
            else uval = 1;
            if (j-1 >= 0) { for (int j2=0; j2<3; ++j2) if (j2 != i2) lval = (lval + dp[i][j-1][j2]) % mod; }
            else lval = 1;
            dp[i][j][i2] = uval * lval % mod;
        }
        ll res = 0;
        for (int i=0; i<3; ++i) res = (res + dp[m-1][n-1][i]) % mod;
        return (int)res;
    }
};
