// 解説AC4(Space:O(k)解)

#include <bits/stdc++.h>
using namespace std;

class Solution {
    const int mod = (int)(1e9) + 7;
public:
    int kInversePairs(int n, int k) {
        vector<int> dp(k+1);
        for (int i=1; i<=n; ++i) {
            vector<int> ndp(k+1);
            ndp[0] = 1;
            for (int j=1; j<=k; ++j) {
                ndp[j] = ((ndp[j] + dp[j]) % mod - ((j-i>=0) ? dp[j-i] : 0) + mod) % mod;
                ndp[j] = (ndp[j] + ndp[j-1]) % mod;
            }
            swap(ndp, dp);
        }
        return (dp[k] - ((k-1>=0) ? dp[k-1] : 0) + mod) % mod;
    }
};
