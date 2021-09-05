#include <bits/stdc++.h>
using namespace std;

// 解説AC,Space:O(1)解

class Solution {
    const long long mod = (long long)(1e9) + 7;
public:
    int countSpecialSubsequences(vector<int>& nums) {
        int n = nums.size();
        vector<long long> dp(3);
        for (int i=0; i<n; ++i) {
            if (nums[i] == 0) dp[0] = (dp[0] * 2 + 1) % mod;
            else dp[nums[i]] = (dp[nums[i]] * 2 + dp[nums[i]-1]) % mod;
        }
        return (int)dp[2];
    }
};
