#include <bits/stdc++.h>
using namespace std;

// 自力AC

class Solution {
    const int INF = (int)(1e9);
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, INF);
        for (int i=0; i<n; ++i) *lower_bound(dp.begin(), dp.end(), nums[i]) = nums[i];
        int res = 0;
        for (int i=0; i<n; ++i) if (dp[i] != INF) res = max(res, i+1);
        return res;
    }
};
