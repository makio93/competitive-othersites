// 学習1回目,自力AC1

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, ll> dp, ndp;
        dp[0] = 1;
        ll res = 0;
        for (int i=0; i<target; ++i) {
            ndp.clear();
            for (const auto& pi : dp) {
                if (pi.second >= 1LL<<32) continue;
                for (const int& num : nums) if (pi.first+num <= target) ndp[pi.first+num] += pi.second;
            }
            swap(dp, ndp);
            res += dp[target];
        }
        return (int)res;
    }
};
