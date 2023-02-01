// 自力AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestPalindrome(string word1, string word2) {
        int n = word1.length(), m = word2.length();
        vector<vector<int>> dp(n+m, vector<int>(n+m, 1));
        for (int i=2; i<=n+m; ++i) for (int l=0; l+i-1<n+m; ++l) {
            int r = l + i - 1;
            if ((l<n?word1[l]:word2[l-n]) == (r<n?word1[r]:word2[r-n])) {
                if (i <= 2) dp[l][r] = i;
                else dp[l][r] = max({ dp[l][r-1], dp[l+1][r], dp[l+1][r-1]+2 });
            }
            else dp[l][r] = max(dp[l+1][r], dp[l][r-1]);
        }
        int res = 0;
        for (int l=0; l<n; ++l) for (int r=0; r<m; ++r) if (word1[l] == word2[r]) res = max(res, dp[l][n+r]);
        return res;
    }
};
