// 解説AC3

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<int> dp(n), pdp(n);
        for (int i=n-1; i>=0; --i) {
            dp[i] = 1;
            for (int j=i+1; j<n; ++j) {
                if (s[i] == s[j]) dp[j] = pdp[j-1] + 2;
                else dp[j] = max(dp[j-1], pdp[j]);
            }
            pdp = dp;
        }
        return dp[n-1];
    }
};
