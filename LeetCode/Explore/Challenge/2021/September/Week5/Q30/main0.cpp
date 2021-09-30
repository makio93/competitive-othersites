#include <bits/stdc++.h>
using namespace std;

// 自力AC

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size(), sum = 0;
        for (int i=0; i<n; ++i) sum += nums[i];
        if (sum%k != 0) return false;
        int tval = sum / k;
        for (int i=0; i<n; ++i) if (nums[i] > tval) return false;
        vector<bool> dp((1<<n), false);
        dp[0] = true;
        for (int i1=0; i1<=n; ++i1) {
            for (int i=0; i<(1<<n); ++i) if (__builtin_popcount(i)==i1 && dp[i]) {
                for (int j=0; j<n; ++j) if (!((i>>j)&1)) {
                    int val = 0;
                    for (int j2=0; j2<n; ++j2) if ((i>>j2)&1) val += nums[j2];
                    int rval = val % tval, aval = rval + nums[j];
                    if (aval <= tval) dp[i|(1<<j)] = true;
                }
            }
        }
        return dp[(1<<n)-1];
    }
};
