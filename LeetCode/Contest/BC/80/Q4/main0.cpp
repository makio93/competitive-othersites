// 本番AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        vector<ll> sums(n+1);
        for (int i=0; i<n; ++i) sums[i+1] = sums[i] + nums[i];
        ll res = 0;
        for (int i=1; i<=n; ++i) {
            if (sums[i]*i < k) {
                res += i;
                continue;
            }
            int li = 0, ri = i;
            while (ri-li > 1) {
                int ci = li + (ri-li) / 2;
                ll cval = (sums[i]-sums[ci]) * (i-ci);
                if (cval < k) ri = ci;
                else li = ci;
            }
            res += i-ri;
        }
        return res;
    }
};
