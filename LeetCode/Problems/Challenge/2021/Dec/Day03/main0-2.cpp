#include <bits/stdc++.h>
using namespace std;

// ヒントあり+自力AC

using ll = long long;
const ll INF = (ll)(-1e18);
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<vector<ll>> dp(n, vector<ll>(2, INF));
        if (nums[0] >= 0) dp[0][0] = nums[0];
        else dp[0][1] = abs(nums[0]);
        for (int i=1; i<n; ++i) {
            if (nums[i] >= 0) dp[i][0] = nums[i];
            else dp[i][1] = abs(nums[i]);
            for (int j=0; j<2; ++j) if (dp[i-1][j] != INF) {
                int bval = (j == 0) ? 1 : -1;
                if (nums[i] < 0) bval *= -1;
                if (bval == 1) dp[i][0] = max(dp[i][0], abs(dp[i-1][j]*nums[i]));
                else dp[i][1] = max(dp[i][1], abs(dp[i-1][j]*nums[i]));
            }
        }
        ll res = INF;
        for (int i=0; i<n; ++i) for (int j=0; j<2; ++j) if (dp[i][j] != INF) {
            res = max(res, dp[i][j]*(j==0?1:-1));
        }
        return (int)res;
    }
};
