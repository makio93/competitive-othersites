// 本番AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll LINF = (ll)(1e18);
class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        int n = nums.size();
        ll res = -LINF;
        for (int i=1; i<1<<n; ++i) {
            ll val = 1;
            for (int j=0; j<n; ++j) if (i&(1LL<<j)) val *= nums[j];
            res = max(res, val);
        }
        return res;
    }
};
