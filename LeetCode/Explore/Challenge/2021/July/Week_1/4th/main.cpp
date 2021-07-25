#include <bits/stdc++.h>
using namespace std;

class Solution {
    const long long mod = (long long)(1e9) + 7;
    const vector<vector<int>> rules = {
        { 1 },
        { 0, 2 },
        { 0, 1, 3, 4 }, 
        { 2, 4 },
        { 0 }
    };
public:
    int countVowelPermutation(int n) {
        vector<vector<long long>> dp(n, vector<long long>(5));
        for (int i=0; i<5; ++i) dp[0][i] = 1;
        for (int i=0; i<n-1; ++i) for (int j=0; j<5; ++j) {
            for (int t : rules[j]) dp[i+1][t] = (dp[i+1][t] + dp[i][j]) % mod;
        }
        long long res = 0;
        for (int i=0; i<5; ++i) res = (res + dp[n-1][i]) % mod;
        return (int)res;
    }
};
