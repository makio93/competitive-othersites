// 学習1回目,自力AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        pair<int, int> rvals = { 0, -1 };
        vector<vector<bool>> dp(n, vector<bool>(n));
        for (int i=0; i<n; ++i) {
            dp[i][i] = true;
            rvals = max(rvals, { 1, -i });
            if (i+1<n && s[i]==s[i+1]) {
                dp[i][i+1] = true;
                rvals = max(rvals, { 2, -i });
            }
        }
        for (int k=2; k<n; ++k) for (int i=0; i+k<n; ++i) if (s[i]==s[i+k] && dp[i+1][i+k-1]) {
            dp[i][i+k] = true;
            rvals = max(rvals, { k+1, -i });
        }
        return s.substr(-rvals.second, rvals.first);
    }
};
