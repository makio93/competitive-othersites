// 解説AC3(DP,メモリ削減)

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll mod = (ll)(1e9) + 7;
class Solution {
public:
    int numberOfArrays(string s, int k) {
        int n = s.length(), m = to_string(k).length();
        vector<ll> dp(m+1);
        dp[0] = 1;
        for (int i=0; i<n; ++i) {
            if (s[i] != '0') {
                ll sval = s[i] - '0';
                for (int j=i; j<n; ++j) {
                    if (sval > (ll)k) break;
                    dp[(j+1)%(m+1)] = (dp[(j+1)%(m+1)] + dp[i%(m+1)]) % mod;
                    if (j+1 < n) sval = sval * 10 + s[j+1] - '0';
                }
            }
            dp[i%(m+1)] = 0;
        }
        return (int)dp[n%(m+1)];
    }
};
