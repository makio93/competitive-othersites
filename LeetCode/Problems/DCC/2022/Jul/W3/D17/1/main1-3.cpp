// 学習1回目,解説AC3

#include <bits/stdc++.h>
using namespace std;

const int mod = (int)(1e9) + 7;
class Solution {
    vector<vector<int>> memo;
    int calc(int n, int k) {
        if (memo[n][k] != -1) return memo[n][k];
        if (n == 1) return memo[n][k] = 1;
        if (k == 0) return memo[n][k] = 1;
        return memo[n][k] = ((calc(n-1, k) + (k-n>=0 ? -calc(n-1, k-n) + mod : 0)) % mod + calc(n, k-1)) % mod;
    }
public:
    int kInversePairs(int n, int k) {
        memo.resize(n+1, vector<int>(k+1, -1));
        return (calc(n, k) + (k-1>=0 ? -calc(n, k-1) + mod : 0)) % mod;
    }
};
