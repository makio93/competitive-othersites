// 本番AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll mod = (ll)(1e9) + 7;
class Solution {
public:
    int sumOfPower(vector<int>& nums) {
        int n = nums.size();
        sort(nums.rbegin(), nums.rend());
        ll val = 0, res = 0;
        for (int i=n-1; i>=1; --i) {
            val = (val * 2 % mod + nums[i]) % mod;
            res = (res + (ll)nums[i-1] * nums[i-1] % mod * val % mod) % mod;
        }
        for (int i=0; i<n; ++i) res = (res + (ll)nums[i] * nums[i] % mod * nums[i] % mod) % mod;
        return (int)res;
    }
};
