// 本番AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll LINF = (ll)(1e18);
class Solution {
public:
    long long minCost(vector<int>& nums, int x) {
        int n = nums.size();
        vector<int> vals = nums;
        ll res = accumulate(vals.begin(), vals.end(), 0LL);
        for (int i=1; i<n; ++i) {
            for (int j=0; j<n; ++j) vals[j] = min(vals[j], nums[(j+i)%n]);
            res = min(res, accumulate(vals.begin(), vals.end(), 0LL) + (ll)x*i);
        }
        return res;
    }
};
