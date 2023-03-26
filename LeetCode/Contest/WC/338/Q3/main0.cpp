// 本番AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
class Solution {
public:
    vector<ll> minOperations(vector<int>& nums, vector<int>& queries) {
        int n = nums.size(), m = queries.size();
        sort(nums.begin(), nums.end());
        vector<ll> sums(n+1);
        for (int i=0; i<n; ++i) sums[i+1] = sums[i] + nums[i];
        vector<ll> ans(m);
        for (int i=0; i<m; ++i) {
            int id = lower_bound(nums.begin(), nums.end(), queries[i]) - nums.begin();
            ans[i] += (sums[n] - sums[id]) - (ll)(n-id) * queries[i];
            ans[i] += (ll)id * queries[i] - sums[id];
        }
        return ans;
    }
};
