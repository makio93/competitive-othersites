// 解説AC2

#include <bits/stdc++.h>
using namespace std;

const int mod = (int)(1e9) + 7;
class Solution {
public:
    int numWays(vector<string>& words, string target) {
        int n = words.size(), m = target.length(), k = words.front().length();
        vector<vector<int>> ccnt(k, vector<int>(26));
        for (int i=0; i<n; ++i) for (int j=0; j<k; ++j) ccnt[j][words[i][j]-'a']++;
        vector<vector<long long>> dp(m+1, vector<long long>(k+1, -1));
        function<long long(int,int)> f = [&](int i, int j) {
            if (dp[i][j] != -1) return dp[i][j];
            if (i==0 || j==0) return dp[i][j] = i == 0 ? 1 : 0;
            return dp[i][j] = (f(i, j-1) + f(i-1, j-1) * ccnt[j-1][target[i-1]-'a']) % mod;
        };
        return (int)f(m, k);
    }
};
