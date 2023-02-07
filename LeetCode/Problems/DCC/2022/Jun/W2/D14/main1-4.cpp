// 解説AC4

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.length(), m = word2.length();
        vector<int> dp(m+1);
        for (int i=0; i<=n; ++i) {
            vector<int> ndp(m+1);
            for (int j=0; j<=m; ++j) {
                if (i==0 || j==0) ndp[j] = i+j;
                else {
                    if (word1[i-1] == word2[j-1]) ndp[j] = dp[j-1];
                    else ndp[j] = min(dp[j], ndp[j-1]) + 1;
                }
            }
            swap(ndp, dp);
        }
        return dp[m];
    }
};
