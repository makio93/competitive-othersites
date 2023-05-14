// 自力AC2

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& nums) {
        int n = nums.size();
        vector<int> memo(1<<n, -1);
        auto dfs = [&](auto& dfs, int si) -> int {
            if (memo[si] != -1) return memo[si];
            if (si == 0) return memo[si] = 0;
            int val = 0;
            for (int i=0; i<n; ++i) for (int j=i+1; j<n; ++j) if ((si&(1<<i)) && (si&(1<<j))) {
                val = max(val, dfs(dfs, si^(1<<i)^(1<<j)) + gcd(nums[i], nums[j]) * (__builtin_popcount(si)/2));
            }
            return memo[si] = val;
        };
        return dfs(dfs, (1<<n)-1);
    }
};
