// 解説AC1

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
        queue<int> que;
        dist[k-1] = 0;
        que.push(k-1);
        while (!que.empty()) {
            int vi = que.front(); que.pop();
            int di = dist[vi];
            for (auto& tvi : g[vi]) {
                int ti = tvi.first, ndi = di + tvi.second;
                if (dist[ti] <= ndi) continue;
                dist[ti] = ndi;
                que.push(ti);
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
