// 学習1回目,解説AC1

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        string rs(s.rbegin(), s.rend());
        vector<vector<int>> dp(n+1, vector<int>(n+1));
        pair<int, int> mval = { 0, 0 };
        for (int i=0; i<=n; ++i) for (int j=0; j<=n; ++j) {
            if (i==0 || j==0 || s[i-1]!=rs[j-1]) dp[i][j] = 0;
            else {
                dp[i][j] = dp[i-1][j-1] + 1;
                if (i-dp[i][j] == n-j) mval = max(mval, { dp[i][j], -(i-dp[i][j]) });
            }
        }
        return s.substr(-mval.second, mval.first);
    }
};
