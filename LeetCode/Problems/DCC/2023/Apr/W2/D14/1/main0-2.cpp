// 学習1回目,自力AC2

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<int> dp(n), ndp;
        for (int i=0; i<n; ++i) {
            ndp = dp;
            ndp[i] = 1;
            for (int j=i-1; j>=0; --j) {
                if (s[j] == s[i]) ndp[j] = max(ndp[j], dp[j+1]+2);
                ndp[j] = max({ ndp[j], ndp[j+1], dp[j], 1 });
            }
            swap(ndp, dp);
        }
        return max(1, dp[0]);
    }
};
