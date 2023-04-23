// 自力AC2(配るDP)

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll mod = (ll)(1e9) + 7;
class Solution {
public:
    int numberOfArrays(string s, int k) {
        int n = s.length();
        vector<ll> dp(n+1);
        dp[0] = 1;
        for (int i=0; i<n; ++i) {
            if (s[i] == '0') continue;
            int ri = i;
            ll val = s[ri] - '0';
            while (val <= (ll)k) {
                dp[ri+1] = (dp[ri+1] + dp[i]) % mod;
                ++ri;
                if (ri >= n) break;
                val = val * 10 + s[ri] - '0';
            }
        }
        return (int)dp[n];
    }
};
