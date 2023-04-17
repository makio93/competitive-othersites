// 自力AC

#include <bits/stdc++.h>
using namespace std;

const long long mod = (long long)(1e9) + 7;
class Solution {
public:
    int numWays(vector<string>& words, string target) {
        int n = words.size(), m = target.length(), l = words.front().length();
        vector<vector<int>> ccnt(l, vector<int>(26));
        for (int i=0; i<n; ++i) for (int j=0; j<l; ++j) ccnt[j][words[i][j]-'a']++;
        vector<long long> dp(l+1);
        dp[0] = 1;
        for (int i=0; i<m; ++i) {
            for (int j=0; j<l; ++j) dp[j+1] = (dp[j+1] + dp[j]) % mod;
            for (int j=l; j>0; --j) dp[j] = dp[j-1] * ccnt[j-1][target[i]-'a'] % mod;
            dp[0] = 0;
        }
        long long res = 0;
        for (int i=0; i<=l; ++i) res = (res + dp[i]) % mod;
        return (int)res;
    }
};
