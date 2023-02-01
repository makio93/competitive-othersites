// 本番AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<bool> dp(n+1);
        dp[0] = true;
        for (int i=1; i<n; ++i) {
            if (dp[i-1] && nums[i-1]==nums[i]) dp[i+1] = true;
            if (i-2>=0 && dp[i-2] && ((nums[i-2]==nums[i]&&nums[i-1]==nums[i])||
                (nums[i-1]-nums[i-2]==1&&nums[i]-nums[i-1]==1))) dp[i+1] = true; 
        }
        return dp[n];
    }
};
