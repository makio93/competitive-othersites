// バチャ終了後,TLE2

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = (ll)(1e9);
const ll BIG = (ll)(2e8);
class Solution {
public:
    int minimumFinishTime(vector<vector<int>>& tires, int changeTime, int numLaps) {
        int n = tires.size();
        sort(tires.begin(), tires.end(), [](vector<int> a, vector<int> b) {
            return make_pair(a[0], -a[1]) > make_pair(b[0], -b[1]);
        });
        vector<pair<int, int>> dp(n+1, { (int)INF, -1 });
        for (int i=0; i<n; ++i) {
            *lower_bound(dp.begin(), dp.end(), make_pair(tires[i][1], -1)) = make_pair(tires[i][1], i);
        }
        vector<int> tids;
        for (int i=0; i<n; ++i) {
            if (dp[i].first == (int)INF) break;
            tids.push_back(dp[i].second);
        }
        int m = tids.size();
        vector<ll> dist(numLaps+1, INF);
        dist[0] = 0;
        for (int i=0; i<numLaps; ++i) {
            for (int j=0; j<m; ++j) {
                ll ndi = dist[i] + (i==0?0:changeTime), add = tires[tids[j]][0], rval = tires[tids[j]][1];
                unordered_map<int, ll> ndist;
                for (int j2=i+1; j2<=numLaps; ++j2) {
                    ndi += add;
                    if (ndi > BIG) break;
                    if (ndist.find(j2)!=ndist.end() && ndist[j2]<=ndi) break;
                    if (ndist.find(j2) == ndist.end()) ndist[j2] = ndi;
                    else ndist[j2] = min(ndist[j2], ndi);
                    add *= rval;
                }
                for (auto pi : ndist) dist[pi.first] = min(dist[pi.first], pi.second);
            }
        }
        return (int)dist[numLaps];
    }
};
