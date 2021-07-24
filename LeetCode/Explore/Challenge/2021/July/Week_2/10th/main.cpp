#include <bits/stdc++.h>
using namespace std;

// 自力AC

class Solution {
    const long long mod = (long long)(1e9) + 7;
public:
    int numDecodings(string s) {
        int n = s.length();
        vector<long long> dp(n+1);
        dp[0] = 1;
        for (int i=1; i<=n; ++i) {
            if (s[i-1] == '*') dp[i] = (dp[i] + dp[i-1] * 9) % mod;
            else if (s[i-1] != '0') dp[i] = (dp[i] + dp[i-1]) % mod;
            if (i-2 >= 0) {
                if (s[i-2] == '*') {
                    if (s[i-1] == '*') dp[i] = (dp[i] + dp[i-2] * 15) % mod;
                    else if (s[i-1]>='0' && s[i-1]<='6') dp[i] = (dp[i] + dp[i-2] * 2) % mod;
                    else dp[i] = (dp[i] + dp[i-2]) % mod;
                }
                else if (s[i-2] == '1') {
                    if (s[i-1] == '*') dp[i] = (dp[i] + dp[i-2] * 9) % mod;
                    else dp[i] = (dp[i] + dp[i-2]) % mod;
                }
                else if (s[i-2] == '2') {
                    if (s[i-1] == '*') dp[i] = (dp[i] + dp[i-2] * 6) % mod;
                    else if (s[i-1]>='0' && s[i-1]<='6') dp[i] = (dp[i] + dp[i-2]) % mod;
                }
            }
        }
        return (int)dp[n];
    }
};
