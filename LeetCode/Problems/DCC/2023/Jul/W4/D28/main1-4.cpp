// 解説AC4

#include <bits/stdc++.h>
using namespace std;

const int INF = (int)(1e9);
class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -INF);
        for (int i=0; i<n; ++i) for (int j=0; j+i<n; ++j) {
            if (i == 0) dp[j] = nums[j];
            else dp[j] = max(nums[j]-dp[j+1], nums[j+i]-dp[j]);
        }
        return dp[0] >= 0;
    }
};
