// 自力AC

#include <bits/stdc++.h>
using namespace std;

const int INF = (int)(1e9);
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int m = times.size();
        vector<vector<pair<int, int>>> g(n);
        for (auto& vi : times) g[vi[0]-1].emplace_back(vi[1]-1, vi[2]);
        vector<int> dist(n, INF);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        dist[k-1] = 0;
        pq.emplace(0, k-1);
        while (!pq.empty()) {
            auto tr = pq.top(); pq.pop();
            int di = tr.first, vi = tr.second;
            if (dist[vi] != di) continue;
            for (auto& tpi : g[vi]) {
                int ndi = di + tpi.second, ti = tpi.first;
                if (dist[ti] <= ndi) continue;
                dist[ti] = ndi;
                pq.emplace(ndi, ti);
            }
        }
        int res = 0;
        for (int i=0; i<n; ++i) {
            if (dist[i] == INF) {
                res = -1;
                break;
            }
            res = max(res, dist[i]);
        }
        return res;
    }
};
