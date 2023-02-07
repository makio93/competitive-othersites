// 自力AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
    const int mod = (int)(1e9) + 7;
    const vector<vector<int>> mat = {
        { 0, 1, 1, 0, 1 },
        { 1, 0, 1, 0, 0 },
        { 0, 1, 0, 1, 0 },
        { 0, 0, 1, 0, 0 },
        { 0, 0, 1, 1, 0 }
    };
public:
    int countVowelPermutation(int n) {
        vector<vector<int>> dp(n, vector<int>(5));
        for (int i=0; i<5; ++i) dp[0][i] = 1;
        for (int i=1; i<n; ++i) for (int j=0; j<5; ++j) for (int k=0; k<5; ++k) dp[i][j] = (dp[i][j] + dp[i-1][k] * mat[j][k]) % mod;
        int res = 0;
        for (int i=0; i<5; ++i) res = (res + dp[n-1][i]) % mod;
        return res;
    }
};
