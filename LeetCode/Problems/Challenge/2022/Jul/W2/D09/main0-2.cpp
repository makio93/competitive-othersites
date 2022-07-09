// 自力AC2

#include <bits/stdc++.h>
using namespace std;

class Solution {
    const int INF = (int)(1.5e9);
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        multiset<int> vals;
        vector<int> dp(n, -INF);
        dp[0] = nums[0];
        vals.insert(dp[0]);
        for (int i=1; i<n; ++i) {
            if (i-k-1 >= 0) vals.erase(vals.find(dp[i-k-1]));
            dp[i] = *vals.rbegin() + nums[i];
            vals.insert(dp[i]);
        }
        return dp[n-1];
    }
};
