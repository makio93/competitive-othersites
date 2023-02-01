// 自力AC2-2

#include <bits/stdc++.h>
using namespace std;

class Solution {
    const int INF = (int)(1.5e9);
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n, -INF);
        map<int, int> vals;
        dp[0] = nums[0];
        vals[dp[0]]++;
        for (int i=1; i<n; ++i) {
            if (i-k-1 >= 0) {
                vals[dp[i-k-1]]--;
                if (vals[dp[i-k-1]] == 0) vals.erase(dp[i-k-1]);
            }
            dp[i] = vals.rbegin()->first + nums[i];
            vals[dp[i]]++;
        }
        return dp[n-1];
    }
};
