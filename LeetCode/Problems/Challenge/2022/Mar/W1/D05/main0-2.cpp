// 自力2,AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        vector<int> vcnt((int)(1e4)+1);
        for (int i=0; i<n; ++i) vcnt[nums[i]]++;
        vector<vector<int>> dp((int)(1e4)+1, vector<int>(2));
        for (int i=1; i<=(int)(1e4); ++i) {
            if (i==1) dp[i][1] = i * vcnt[i];
            else {
                dp[i][1] = max(dp[i-2][1], dp[i-1][0]) + vcnt[i] * i;
                dp[i][0] = max(dp[i-1][1], dp[i-1][0]);
            }
        }
        return max(dp[(int)(1e4)][0], dp[(int)(1e4)][1]);
    }
};
