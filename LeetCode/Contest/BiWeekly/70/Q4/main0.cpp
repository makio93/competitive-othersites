#include <bits/stdc++.h>
using namespace std;

// 本番AC

const long long mod = (long long)(1e9) + 7;
class Solution {
public:
    int numberOfWays(string corridor) {
        int n = corridor.length();
        vector<int> ssum(n+1);
        for (int i=0; i<n; ++i) ssum[i+1] = ssum[i] + (corridor[i]=='S' ? 1 : 0);
        vector<long long> dp(n+1), dpsum(n+1);
        dp[0] = 1;
        dpsum[ssum[0]] = (dpsum[ssum[0]] + dp[0]) % mod;
        for (int i=1; i<=n; ++i) {
            if (ssum[i]-2 >= 0) dp[i] = (dp[i] + dpsum[ssum[i]-2]) % mod;
            dpsum[ssum[i]] = (dpsum[ssum[i]] + dp[i]) % mod;
        }
        return (int)(dp[n] % mod);
    }
};
