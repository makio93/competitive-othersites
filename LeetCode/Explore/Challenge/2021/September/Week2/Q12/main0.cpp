#include <bits/stdc++.h>
using namespace std;

// 自力AC

using ll = long long;
class Solution {
    const ll INF = (ll)(1e15);
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        int m = edges.size();
        vector<vector<int>> vcnt(m, vector<int>(2));
        vector<vector<pair<int, int>>> g(n);
        for (int i=0; i<m; ++i) {
            g[edges[i][0]].emplace_back(edges[i][1], i);
            g[edges[i][1]].emplace_back(edges[i][0], i);
        }
        vector<ll> dist(n, INF);
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> que;
        que.emplace(0, 0);
        dist[0] = 0;
        while (!que.empty()) {
            auto [di, vi] = que.top(); que.pop();
            if (dist[vi] != di) continue;
            for (auto p : g[vi]) {
                int ti = p.first, eid = p.second, ci = edges[eid][2], vid = (ti > vi) ? 0 : 1;
                ll ndi = di + ci + 1;
                if (ndi <= (ll)maxMoves) {
                    vcnt[eid][vid] = max(vcnt[eid][vid], ci);
                    vcnt[eid][1-vid] = max(vcnt[eid][1-vid], ci);
                    if (dist[ti] > ndi) {
                        dist[ti] = ndi;
                        que.emplace(ndi, ti);
                    }
                }
                else {
                    int ci2 = (int)((ci + 1) - (ndi - (ll)(maxMoves)));
                    vcnt[eid][vid] = max(vcnt[eid][vid], ci2);
                    if (vcnt[eid][1-vid]+vcnt[eid][vid] >= ci) vcnt[eid][vid] = vcnt[eid][1-vid] = ci;
                }
            }
        }
        ll res = 0;
        for (int i=0; i<n; ++i) if (dist[i] != INF) ++res;
        for (int i=0; i<m; ++i) res += min(edges[i][2], vcnt[i][0]+vcnt[i][1]);
        return res;
    }
};
