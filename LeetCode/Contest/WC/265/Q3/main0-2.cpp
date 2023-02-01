#include <bits/stdc++.h>
using namespace std;

// 本番AC

using ll = long long;
class Solution {
    ll INF = (ll)(1e15);
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        int n = nums.size();
        vector<ll> lnums(n);
        for (int i=0; i<n; ++i) lnums[i] = nums[i];
        sort(lnums.begin(), lnums.end());
        auto rnums = lnums;
        for (int i=0; i<n; ++i) rnums[i] *= -1;
        sort(rnums.begin(), rnums.end());
        vector<ll> dist(1001, INF);
        queue<ll> que;
        dist[start] = 0;
        que.push(start);
        while (!que.empty()) {
            ll xval = que.front(); que.pop();
            ll d = dist[xval], nd = d + 1;
            auto itr1 = lower_bound(lnums.begin(), lnums.end(), goal-xval);
            auto itr2 = lower_bound(rnums.begin(), rnums.end(), goal-xval);
            if (itr1!=lnums.end() && *itr1==goal-xval) return nd;
            if (itr2!=rnums.end() && *itr2==goal-xval) return nd;
            if (goal>=0 && (ll)(xval)>=0 && (((ll)xval)^goal)<(ll)INF) {
                auto itr3 = lower_bound(lnums.begin(), lnums.end(), (xval^goal));
                if (itr3!=lnums.end() && *itr3==(xval^goal)) return nd;
            }
            int t1 = lower_bound(lnums.begin(), lnums.end(), -xval) - lnums.begin();
            for (int i=t1; i<n; ++i) {
                ll tval = xval + lnums[i];
                if (tval>1000) break;
                if (tval<0) continue;
                if (dist[tval] <= nd) continue;
                dist[tval] = nd;
                que.push(tval);
            }
            int t2 = lower_bound(rnums.begin(), rnums.end(), -xval) - rnums.begin();
            for (int i=t2; i<n; ++i) {
                ll tval = xval + rnums[i];
                if (tval>1000) break;
                if (tval<0) continue;
                if (dist[tval] <= nd) continue;
                dist[tval] = nd;
                que.push(tval);
            }
            if ((ll)(xval) >= 0) {
                for (int i=0; i<n; ++i) {
                    if (lnums[i]<0) continue;
                    if ((((ll)xval)^lnums[i]) >= (ll)INF) continue;
                    ll tval = xval ^ lnums[i];
                    if (tval<0 || tval>1000) continue;
                    if (dist[tval] <= nd) continue;
                    dist[tval] = nd;
                    que.push(tval);
                }
            }
        }
        if (goal>=0 && goal<=1000 && dist[goal]!=INF) return dist[goal];
        else return -1;
    }
};
