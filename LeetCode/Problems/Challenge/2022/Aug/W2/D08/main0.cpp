// 自力AC

#include <bits/stdc++.h>
using namespace std;

const int INF = (int)(1e9);
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, INF);
        for (int i=0; i<n; ++i) *lower_bound(dp.begin(), dp.end(), nums[i]) = nums[i];
        int res = n;
        for (int i=0; i<n; ++i) if (dp[i] == INF) {
            res = i;
            break;
        }
        return res;
    }
};
