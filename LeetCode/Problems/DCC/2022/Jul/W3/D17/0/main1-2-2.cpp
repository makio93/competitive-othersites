// 解説AC2-2

#include <bits/stdc++.h>
using namespace std;

class Solution {
    const int mod = (int)(1e9) + 7;
public:
    int kInversePairs(int n, int k) {
        vector<int> dp(k+1), ndp;
        dp[0] = 1;
        for (int i=1; i<n; ++i) {
            ndp.assign(k+1, 0);
            for (int j=0; j<=k&&j<=i*(i+1)/2; ++j) {
                ndp[j] = ((dp[j] - (j-i-1>=0 ? dp[j-i-1] : 0) + mod) % mod + (j-1>=0 ? ndp[j-1] : 0)) % mod;
            }
            swap(ndp, dp);
        }
        return dp[k];
    }
};
