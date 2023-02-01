// バチャ終了後,TLE

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = (int)(1e9);
class Solution {
public:
    int minimumFinishTime(vector<vector<int>>& tires, int changeTime, int numLaps) {
        int n = tires.size();
        vector<ll> dist(numLaps+1, INF);
        dist[0] = 0;
        for (int i=0; i<numLaps; ++i) {
            for (int j=0; j<n; ++j) {
                //if (dist[i]+(i==0?0:changeTime)+tires[tids[j]][0] > dist[i+1]) break;
                ll ndi = dist[i] + (i==0?0:changeTime), add = tires[j][0], rval = tires[j][1];
                for (int j2=i+1; j2<=numLaps; ++j2) {
                    ndi += add;
                    if (ndi > INF) break;
                    dist[j2] = min(dist[j2], ndi);
                    add *= rval;
                }
            }
        }
        return (int)dist[numLaps];
    }
};
