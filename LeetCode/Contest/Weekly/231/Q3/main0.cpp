// 

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        int m = edges.size();
        vector<vector<pair<int, int>>> g(n);
        for (int i=0; i<m; ++i) {
            g[edges[i][0]-1].emplace_back(edges[i][1]-1, edges[i][2]);
            g[edges[i][1]-1].emplace_back(edges[i][0]-1, edges[i][2]);
        }
        vector<long long> dist(n, (long long)(1e18));
        vector<long long> dcnt(n);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> que;
        que.emplace(0, n-1);
        dist[n-1] = 0;
        dcnt[n-1] = 1;
        const long long mod = (1e9) + 7;
        while (!que.empty()) {
            auto p = que.top(); que.pop();
            long long d = p.first;
            int v = p.second;
            if (dist[v] != d) continue;
            long long dc = dcnt[v];
            for (auto np : g[v]) {
                long long nd = d + np.second; int nv = np.first;
                if (dist[nv] > d) dcnt[nv] = (dcnt[nv] + dc) % mod;
                if (dist[nv] <= nd) continue;
                que.emplace(nd, nv);
                dist[nv] = nd;
            }
        }
        return (int)(dcnt[0]);
    }
};
