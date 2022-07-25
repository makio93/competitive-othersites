// 本番WA2

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestPalindrome(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size();
        reverse(word2.begin(), word2.end());
        int ans = 0;
        vector<vector<int>> dp(n1+1, vector<int>(n2+1));
        for (int i=0; i<n1; ++i) for (int j=0; j<n2; ++j) {
            dp[i+1][j+1] = max(dp[i+1][j+1], max(dp[i][j+1], dp[i+1][j]));
            if (word1[i] == word2[j]) dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j]+1);
        }
        ans = max(ans, dp[n1][n2]*2);
        if (ans > 0) {
            dp = vector<vector<int>>(n1+1, vector<int>(n2+1));
            for (int i=0; i<n1; ++i) for (int j=0; j<n2; ++j) {
                dp[i+1][j+1] = max(dp[i+1][j+1], max(dp[i][j+1], dp[i+1][j]));
                if ((i!=n1-1) && (word1[i]==word2[j])) dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j]+1);
            }
            ans = max(ans, dp[n1][n2]*2+1);
            dp = vector<vector<int>>(n1+1, vector<int>(n2+1));
            for (int i=0; i<n1; ++i) for (int j=0; j<n2; ++j) {
                dp[i+1][j+1] = max(dp[i+1][j+1], max(dp[i][j+1], dp[i+1][j]));
                if ((j!=n2-1) && (word1[i]==word2[j])) dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j]+1);
            }
            ans = max(ans, dp[n1][n2]*2+1);
        } 
        return ans;
    }
};
