// 自力4,AC,計算量改善2

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        nums.push_back(0);
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<pair<int, int>> runs;
        runs.emplace_back(nums.front(), 1);
        for (int i=1; i<n; ++i) {
            if (nums[i] == runs.back().first) runs.back().second++;
            else runs.emplace_back(nums[i], 1);
        }
        int m = runs.size();
        vector<vector<int>> dp(3, vector<int>(2));
        for (int i=1; i<m; ++i) {
            if (runs[i].first-runs[i-1].first <= 1) {
                dp[(i+1)%3][1] = max(dp[(i+2)%3][1], dp[i%3][0]) + runs[i].first * runs[i].second;
            }
            else dp[(i+1)%3][1] = max(dp[i%3][1], dp[i%3][0]) + runs[i].first * runs[i].second;
            dp[(i+1)%3][0] = max(dp[i%3][1], dp[i%3][0]);
        }
        return max(dp[m%3][0], dp[m%3][1]);
    }
};
