// 学習1回目,自力AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll mod = (ll)(1e9) + 7;
class Solution {
public:
    int kInversePairs(int n, int k) {
        vector<ll> dp(k+2);
        dp[1] = 1;
        for (int i=0; i<=k; ++i) dp[i+1] = (dp[i+1] + dp[i]) % mod;
        for (int i=1; i<=n-1; ++i) {
            for (int j=k+1; j>=1; --j) {
                int li = max(0, j-i-1);
                dp[j] = (dp[j] - dp[li] + mod) % mod;
            }
            for (int j=0; j<=k; ++j) dp[j+1] = (dp[j+1] + dp[j]) % mod;
        }
        return (int)((dp[k+1] - dp[k] + mod) % mod);
    }
};
