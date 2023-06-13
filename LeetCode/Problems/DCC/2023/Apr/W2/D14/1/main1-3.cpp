// 学習1回目,解説AC3

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<int> dp(n), pdp;
        for (int i=0; i<n; ++i) {
            dp[i] = 1;
            for (int j=i-1; j>=0; --j) {
                dp[j] = max(dp[j+1], pdp[j]);
                if (s[j] == s[i]) dp[j] = max(dp[j], pdp[j+1]+2);
            }
            pdp = dp;
        }
        return dp[0];
    }
};
