// 自力AC1

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(1<<n);
        for (int i=1; i<1<<n; ++i) if (__builtin_popcount(i)%2 == 0) {
            for (int j1=0; j1<n; ++j1) for (int j2=j1+1; j2<n; ++j2) if ((i&(1<<j1)) && (i&(1<<j2))) {
                dp[i] = max(dp[i], dp[i^(1<<j1)^(1<<j2)]+(__builtin_popcount(i)/2)*gcd(nums[j1],nums[j2]));
            }
        }
        return dp[(1<<n)-1];
    }
};
