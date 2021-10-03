#include <bits/stdc++.h>
using namespace std;

// 自力AC

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1);
        dp[0] = 1; dp[1] = -1;
        int val = 0;
        for (int i=0; i<n; ++i) {
            val += dp[i];
            dp[i+1]++; dp[min(n,i+nums[i]+1)]--;
            if (val == 0) return false;
        }
        return true;
    }
};
