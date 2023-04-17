// 解説AC1

#include <bits/stdc++.h>
using namespace std;

const int mod = (int)(1e9) + 7;
class Solution {
public:
    int numWays(vector<string>& words, string target) {
        int n = words.size(), m = target.length(), k = words.front().length();
        vector<vector<int>> ccnt(k, vector<int>(26));
        for (int i=0; i<n; ++i) for (int j=0; j<k; ++j) ccnt[j][words[i][j]-'a']++;
        vector<vector<long long>> dp(m+1, vector<long long>(k+1));
        dp[0][0] = 1;
        for (int i=0; i<=m; ++i) {
            for (int j=0; j<k; ++j) {
                if (i < m) dp[i+1][j+1] = (dp[i][j] * ccnt[j][target[i]-'a']) % mod;
                dp[i][j+1] = (dp[i][j+1] + dp[i][j]) % mod;
            }
        }
        return (int)dp[m][k];
    }
};
