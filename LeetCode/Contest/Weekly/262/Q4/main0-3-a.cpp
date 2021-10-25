#include <bits/stdc++.h>
using namespace std;

// 本番終了後,自力TLE2

using ll = long long;
class Solution {
    ll add = (ll)(1e7);
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        vector<ll> a(n);
        for (int i=0; i<n; ++i) a[i] = nums[i] + add;
        ll sum = 0;
        for (int i=0; i<n; ++i) sum += a[i];
        unordered_map<ll, unordered_set<int>> dp;
        dp[0].insert(0);
        for (int i=0; i<n; ++i) {
            auto ndp = dp;
            for (auto pi : dp) if (*pi.second.begin() < n/2) {
                for (auto itr=pi.second.begin(); itr!=pi.second.end()&&*itr<n/2; ++itr) ndp[pi.first+a[i]].insert(*itr+1);
            }
            swap(ndp, dp);
        }
        ll res = (ll)(1e18);
        for (auto pi : dp) if (pi.second.find(n/2) != pi.second.end()) res = min(res, abs(pi.first*2-sum));
        return (int)(res);
    }
};
