// 自力AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
class Solution {
public:
    ll minCost(vector<int>& nums, vector<int>& cost) {
        int n = nums.size();
        if (n == 1) return 0LL;
        vector<pair<int, int>> nc(n);
        for (int i=0; i<n; ++i) nc[i] = { nums[i], cost[i] };
        sort(nc.begin(), nc.end());
        for (int i=0; i<n; ++i) {
            nums[i] = nc[i].first;
            cost[i] = nc[i].second;
        }
        vector<ll> lsums(n);
        ll csum = cost[0];
        for (int i=1; i<n; ++i) {
            lsums[i] = lsums[i-1] + csum * (nums[i] - nums[i-1]);
            csum += cost[i];
        }
        ll rsum = 0, res = lsums[n-1];
        csum = cost[n-1];
        for (int i=n-2; i>=0; --i) {
            rsum += csum * (nums[i+1] - nums[i]);
            res = min(res, lsums[i]+rsum);
            csum += cost[i];
        }
        return res;
    }
};
