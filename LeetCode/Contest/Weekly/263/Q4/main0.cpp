#include <bits/stdc++.h>
using namespace std;

// 本番AC

class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        int m = edges.size();
        vector<vector<int>> g(n);
        for (int i=0; i<m; ++i) {
            g[edges[i][0]-1].push_back(edges[i][1]-1);
            g[edges[i][1]-1].push_back(edges[i][0]-1);
        }
        vector<set<int>> dist(n);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
        dist[0].insert(0);
        que.emplace(0, 0);
        while (!que.empty()) {
            auto [d, v] = que.top(); que.pop();
            if (dist[v].find(d) == dist[v].end()) continue;
            int td = d + ((d/change%2 != 1) ? 0 : (change - d%change));
            for (auto ti : g[v]) {
                int nd = td + time;
                if (dist[ti].find(nd) != dist[ti].end()) continue;
                if ((int)(dist[ti].size()) >= 2) {
                    auto nitr = next(dist[ti].begin());
                    if (nd > *nitr) continue;
                    dist[ti].erase(*dist[ti].rbegin());
                    dist[ti].insert(nd);
                }
                else dist[ti].insert(nd);
                que.emplace(nd, ti);
            }
        }
        return *dist[n-1].rbegin();
    }
};
