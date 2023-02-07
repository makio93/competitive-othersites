#include <bits/stdc++.h>
using namespace std;

// 自力AC1,Time:O(nlogn)

class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n, 0);
        map<int, int> vals;
        for (int i=0; i<n; ++i) {
            if (i-k-1 >= 0) {
                vals[dp[i-k-1]]--;
                if (vals[dp[i-k-1]] == 0) vals.erase(dp[i-k-1]);
            }
            dp[i] = nums[i] + (i==0 ? 0 : vals.rbegin()->first);
            vals[dp[i]]++;
        }
        return dp[n-1];
    }
};
