// 自力3,AC,計算量改善1

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> vcnt;
        for (int i=0; i<n; ++i) vcnt[nums[i]]++;
        vector<vector<int>> dp(3, vector<int>(2));
        for (int i=1; i<=(int)(1e4); ++i) {
            dp[i%3][0] = max(dp[(i+2)%3][0], dp[(i+2)%3][1]);
            if (vcnt.find(i) == vcnt.end()) dp[i%3][1] = 0;
            else dp[i%3][1] = max(dp[(i+2)%3][0], dp[(i+1)%3][1]) + vcnt[i] * i;
        }
        return max(dp[(int)(1e4)%3][0], dp[(int)(1e4)%3][1]);
    }
};
