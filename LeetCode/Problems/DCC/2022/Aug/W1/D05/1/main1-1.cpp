// 学習1回目,解説AC1

#include <bits/stdc++.h>
using namespace std;

static const int IMX = numeric_limits<int>::max();
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> dp(target+1);
        dp[0] = 1;
        for (int i=1; i<=target; ++i) for (int j=0; j<n; ++j) {
            if (i-nums[j] < 0) break;
            if (dp[i] <= IMX-dp[i-nums[j]]) dp[i] += dp[i-nums[j]];
        }
        return dp[target];
    }
};
