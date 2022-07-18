// 自力AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
    const int mod = (int)(1e9) + 7;
public:
    int kInversePairs(int n, int k) {
        vector<int> dp(k+2, 0), ndp;
        dp[0] = 1;
        for (int i=0; i<n; ++i) {
            ndp.assign(k+2, 0);
            for (int j=0; j<=k; ++j) {
                ndp[j] = (ndp[j] + dp[j]) % mod;
                ndp[min(k+1,j+i+1)] = (ndp[min(k+1,j+i+1)] - dp[j] + mod) % mod;
            }
            for (int j=0; j<=k; ++j) ndp[j+1] = (ndp[j+1] + ndp[j]) % mod;
            swap(ndp, dp);
        }
        return dp[k];
    }
};
