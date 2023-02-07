#include <bits/stdc++.h>
using namespace std;

// 自力AC,優れていない解法

using ll = long long;
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size();
        vector<vector<tuple<int, ll, ll>>> g(n+2);
        for (int i=0; i<=n; ++i) for (int j=i+1; j<=n+1; ++j) {
            int di = (j==n+1) ? (target) : stations[j-1][0];
            if (i != 0) di -= stations[i-1][0];
            int vali = (j==n+1) ? 0 : stations[j-1][1];
            g[i].emplace_back(j, di, vali);
        }
        vector<unordered_map<int, ll>> dist(n+2);
        priority_queue<tuple<int, ll, int>, vector<tuple<int, ll, int>>, greater<tuple<int, ll, int>>> que;
        dist[0][0] = -startFuel;
        que.emplace(0, -startFuel, 0);
        while (!que.empty() && dist[n+1].empty()) {
            auto [cost, val, vi] = que.top(); que.pop();
            if (dist[vi].find(cost)==dist[vi].end() || dist[vi][cost]!=val) continue;
            for (auto tvi : g[vi]) {
                if (get<1>(tvi) <= -val) {
                    int ncost = cost + (get<0>(tvi)!=n+1 ? 1 : 0);
                    ll nval = val + get<1>(tvi) - get<2>(tvi);
                    if (dist[get<0>(tvi)].find(ncost)!=dist[get<0>(tvi)].end() && dist[get<0>(tvi)][ncost]<=nval) break;
                    dist[get<0>(tvi)][ncost] = nval;
                    que.emplace(ncost, nval, get<0>(tvi));
                }
                else break;
            }
        }
        if (dist[n+1].empty()) return -1;
        else return dist[n+1].begin()->first;
    }
};
