// 解説AC2,DP解

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n));
        pair<int, int> ids = { 1, 0 };
        for (int i=0; i<n; ++i) dp[i][i] = true;
        for (int i=0; i+1<n; ++i) if (s[i] == s[i+1]) {
            dp[i][i+1] = true;
            ids = max(ids, { 2, -i });
        }
        for (int i=3; i<=n; ++i) for (int j=0; j+i-1<n; ++j) if (s[j] == s[j+i-1]) {
            if (dp[j+1][j+i-2]) {
                dp[j][j+i-1] = true;
                ids = max(ids, { i, -j });
            }
        }
        return s.substr(-ids.second, ids.first);
    }
};
