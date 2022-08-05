// 解説AC

#include <bits/stdc++.h>
using namespace std;

const int INF = numeric_limits<int>::max();
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1);
        dp[0] = 1;
        for (int i=1; i<=target; ++i) for (int& num : nums) if (i-num >= 0) dp[i] = (dp[i-num] > INF-dp[i]) ? INF : dp[i-num]+dp[i];
        return dp[target];
    }
};
