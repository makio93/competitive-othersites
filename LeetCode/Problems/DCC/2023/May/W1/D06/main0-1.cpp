// 自力AC1

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll mod = (ll)(1e9) + 7;
class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size(), res = 0;
        vector<ll> twos(n+1);
        twos[0] = 1;
        for (int i=1; i<=n; ++i) twos[i] = twos[i-1] * 2 % mod;
        sort(nums.begin(), nums.end());
        for (int i=0; i<n; ++i) {
            if (nums[i]+nums[i] <= target) res = (res + 1) % mod;
            int li = upper_bound(nums.begin(), nums.begin()+i, target-nums[i]) - nums.begin();
            res = (res + twos[i-li] * ((twos[li] - 1 + mod) % mod)) % mod;
        }
        return (int)res;
    }
};
