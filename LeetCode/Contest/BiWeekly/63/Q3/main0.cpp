#include <bits/stdc++.h>
using namespace std;

// 本番AC

class Solution {
    int INF = (int)(1e9);
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        int m = edges.size(), n = patience.size();
        vector<vector<int>> g(n);
        for (int i=0; i<m; ++i) {
            g[edges[i][0]].push_back(edges[i][1]);
            g[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> dist(n, INF);
        queue<int> que;
        dist[0] = 0;
        que.push(0);
        while (!que.empty()) {
            int v = que.front(); que.pop();
            int d = dist[v], nd = d + 1;
            for (int ti : g[v]) if (dist[ti] > nd) {
                dist[ti] = nd;
                que.push(ti);
            }
        }
        int res = 0;
        for (int i=1; i<n; ++i) {
            int term = dist[i] * 2;
            int val = ((term-1) / patience[i] * patience[i]) + term;
            res = max(res, val);
        }
        return res + 1;
    }
};
