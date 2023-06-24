// 自力AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll LINF = (ll)(1e18);
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<ll> dp(2), ndp;
        dp[1] = -LINF;
        for (int i=0; i<n; ++i) {
            ndp = dp;
            ndp[1] = max(ndp[1], dp[0]-prices[i]-fee);
            ndp[0] = max(ndp[0], dp[1]+prices[i]);
            swap(ndp, dp);
        }
        return (int)max(dp[0], dp[1]);
    }
};
