// 自力AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size(), res = 0;
        vector<unordered_map<int, int>> dp(n);
        for (int i=1; i<n; ++i) {
            for (int j=0; j<i; ++j) {
                int sub = nums[i] - nums[j], val = dp[j].find(sub) == dp[j].end() ? 2 : dp[j][sub] + 1;
                dp[i][sub] = max(dp[i][sub], val);
                res = max(res, dp[i][sub]);
            }
        }
        return res;
    }
};
