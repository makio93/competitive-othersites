#include <bits/stdc++.h>
using namespace std;

// 本番終了後,自力TLE4

using ll = long long;
class Solution {
    ll add = (ll)(1e7);
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        vector<ll> a(n);
        for (int i=0; i<n; ++i) a[i] = nums[i] + add;
        sort(a.begin(), a.end());
        ll sum = 0;
        for (int i=0; i<n; ++i) sum += a[i];
        map<ll, set<int>> dp;
        set<ll> rvals;
        ll val = (ll)(1e15);
        dp[0].insert(0);
        for (int i=0; i<n; ++i) {
            auto ndp = dp;
            for (auto pi : dp) if (*pi.second.begin() < n/2) {
                if ((pi.first+(n/2-*pi.second.rbegin())*a[i]) > val+(sum+1)/2) {
                    ndp.erase(pi.first);
                    continue;
                }
                for (auto itr=next(pi.second.begin()); itr!=pi.second.end(); ++itr) ndp[pi.first+a[i]].insert(*itr+1);
                ndp[pi.first+a[i]].insert(*pi.second.rbegin()+1);
                if (ndp[pi.first+a[i]].find(n/2) != ndp[pi.first+a[i]].end()) {
                    rvals.insert(pi.first+a[i]);
                    val = min(val, abs(sum/2-(pi.first+a[i])));
                    ndp[pi.first+a[i]].erase(n/2);
                    if (ndp[pi.first+a[i]].empty()) ndp.erase(pi.first+a[i]);
                }
            }
            swap(ndp, dp);
        }
        auto litr = rvals.lower_bound(sum/2);
        if (litr==rvals.end() && litr!=rvals.begin()) --litr;
        ll res = abs(*litr*2-sum);
        ++litr;
        if (litr != rvals.end()) res = min(res, abs(*litr*2-sum));
        return (int)(res);
    }
};
