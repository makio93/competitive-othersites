// 自力AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll mod = (ll)(1e9) + 7;
class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        int n = nums.size();
        vector<ll> two(n+1);
        two[0] = 1;
        for (int i=0; i<n; ++i) two[i+1] = two[i] * 2 % mod;
        unordered_map<ll, ll> dp, ndp;
        ll sum = 0, res = 0;
        dp[0] = 1;
        for (int i=0; i<n; ++i) {
            sum += nums[i];
            for (const auto& pi : dp) {
                if (pi.first>=k && sum-pi.first>=k) res = (res + pi.second * two[(n-1)-i] % mod) % mod;
                else ndp[pi.first] = (ndp[pi.first] + pi.second) % mod;
                if (pi.first+nums[i]>=k && sum-(pi.first+nums[i])>=k) res = (res + pi.second * two[(n-1)-i] % mod) % mod;
                else ndp[pi.first+nums[i]] = (ndp[pi.first+nums[i]] + pi.second) % mod;
            }
            swap(dp, ndp);
            ndp.clear();
        }
        return res;
    }
};
