// 自力AC2

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int INF = (int)(1e9);
const ll LINF = (ll)(1e18);
struct BIT {
    int n;
    vector<ll> d;
    BIT(int n=0) : n(n), d(n+1) {}
    void add(int i, ll x=1) { for (i++; i<=n; i+=i&-i) d[i] = min(LINF, d[i]+x); }
    ll sum(int i) {
        ll x = 0;
        for (i++; i; i-=i&-i) x = min(LINF, x+d[i]);
        return x;
    }
    ll sum(int l, int r) { return sum(r-1) - sum(l-1); }
};
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> vlst;
        vlst.push_back(-INF);
        for (int i=0; i<n; ++i) vlst.push_back(nums[i]);
        sort(vlst.begin(), vlst.end());
        vlst.erase(unique(vlst.begin(), vlst.end()), vlst.end());
        int m = vlst.size();
        for (int i=0; i<n; ++i) nums[i] = lower_bound(vlst.begin(), vlst.end(), nums[i]) - vlst.begin();
        vector<BIT> dp(n+1, BIT(m));
        dp[0].add(0);
        for (int i=0; i<n; ++i) for (int j=n; j>0; --j) dp[j].add(nums[i], dp[j-1].sum(0, nums[i]));
        int res = 0;
        for (int i=n; i>0; --i) if (dp[i].sum(0, m) > 0) {
            res = dp[i].sum(0, m);
            break;
        }
        return res;
    }
};
