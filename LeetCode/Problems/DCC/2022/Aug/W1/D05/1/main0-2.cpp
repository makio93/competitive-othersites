// 学習1回目,自力AC2

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<ll> dp(target+1);
        dp[0] = 1;
        for (int i=1; i<=target; ++i) {
            if (dp[i] >= 1LL<<32) continue;
            for (int j=0; j<n; ++j) if (i-nums[j]>=0 && dp[i-nums[j]]<1LL<<32) dp[i] += dp[i-nums[j]];
        }
        return (int)dp[target];
    }
};
