// 解説AC3

#include <bits/stdc++.h>
using namespace std;

const int INF = (int)(1e9);
class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, -INF));
        for (int i=0; i<n; ++i) for (int j=0; j+i<n; ++j) {
            if (i == 0) dp[j][j+i] = nums[j];
            else dp[j][j+i] = max(nums[j]-dp[j+1][j+i], nums[j+i]-dp[j][j+i-1]);
        }
        return dp[0][n-1] >= 0;
    }
};
