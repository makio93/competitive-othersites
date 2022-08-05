// 自力AC

#include <bits/stdc++.h>
using namespace std;

const int INF = numeric_limits<int>::max();
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(target+1);
        dp[0] = 1;
        int res = 0;
        bool zero = false;
        while (!zero) {
            zero = true;
            vector<int> ndp(target+1);
            for (int i=0; i<=target; ++i) if (dp[i] > 0) for (int j=0; j<n; ++j) if (i+nums[j] <= target) {
                if (zero) zero = false;
                ndp[i+nums[j]] = (ndp[i+nums[j]]>INF-dp[i]) ? INF : ndp[i+nums[j]]+dp[i];
            }
            res += ndp[target];
            swap(ndp, dp);
        }
        return res;
    }
};
