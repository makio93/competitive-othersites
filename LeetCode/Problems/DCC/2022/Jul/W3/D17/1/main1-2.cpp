// 学習1回目,解説AC2

#include <bits/stdc++.h>
using namespace std;

const int mod = (int)(1e9) + 7;
class Solution {
public:
    int kInversePairs(int n, int k) {
        vector<int> dp(k+1, 1), ndp;
        for (int i=2; i<=n; ++i) {
            ndp.assign(k+1, 0);
            for (int j=0; j<=k; ++j) ndp[j] = ((dp[j] - (j-i>=0 ? dp[j-i] : 0) + mod) % mod + (j-1>=0 ? ndp[j-1] : 0)) % mod;
            swap(ndp, dp);
        }
        return (dp[k] - (k-1>=0 ? dp[k-1] : 0) + mod) % mod;
    }
};
