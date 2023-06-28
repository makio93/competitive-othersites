// 自力AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        int m = edges.size();
        vector<vector<pair<int, double>>> g(n);
        for (int i=0; i<m; ++i) {
            g[edges[i][0]].emplace_back(edges[i][1], succProb[i]);
            g[edges[i][1]].emplace_back(edges[i][0], succProb[i]);
        }
        vector<double> dists(n);
        priority_queue<pair<double, int>> pq;
        dists[start] = 1.0;
        pq.emplace(1.0, start);
        while (!pq.empty()) {
            auto [di, vi] = pq.top(); pq.pop();
            if (dists[vi] != di) continue;
            for (const auto [ti, tdi] : g[vi]) {
                double ndi = di * tdi;
                if (dists[ti] >= ndi) continue;
                dists[ti] = ndi;
                pq.emplace(ndi, ti);
            }
        }
        return dists[end];
    }
};
