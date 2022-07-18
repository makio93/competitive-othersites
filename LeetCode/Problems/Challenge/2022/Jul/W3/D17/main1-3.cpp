// 解説AC3(メモ化再帰解)

#include <bits/stdc++.h>
using namespace std;

class Solution {
    const int mod = (int)(1e9) + 7;
    vector<vector<int>> memo;
public:
    int kInversePairs(int n, int k) {
        if (memo.empty()) memo.assign(n+1, vector<int>(k+1, -1));
        if (memo[n][k] != -1) return memo[n][k];
        if (n == 0) return memo[n][k] = 0;
        if (k == 0) return memo[n][k] = 1;
        if (k > n*(n-1)/2) return memo[n][k] = 0;
        return memo[n][k] = ((kInversePairs(n, k-1) + kInversePairs(n-1, k)) % mod 
            - ((k-n >= 0) ? kInversePairs(n-1, k-n) : 0) + mod) % mod;
    }
};
