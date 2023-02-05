// 本番AC

#include <bits/stdc++.h>
using namespace std;

const int INF = (int)(1.5e9);
class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int n = nums.size(), li = 0, ri = *max_element(nums.begin(), nums.end());
        vector<vector<int>> dp;
        while (ri-li > 1) {
            int ci = ri - (ri-li) / 2;
            dp.assign(n+1, vector<int>(2, -INF));
            dp[0][0] = 0;
            for (int i=0; i<n; ++i) {
                dp[i+1][0] = max(dp[i][0], dp[i][1]);
                if (nums[i] <= ci) dp[i+1][1] = dp[i][0] + 1;
            }
            if (max(dp[n][0], dp[n][1]) >= k) ri = ci;
            else li = ci;
        }
        return ri;
    }
};
