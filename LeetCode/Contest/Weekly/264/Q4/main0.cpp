#include <bits/stdc++.h>
using namespace std;

// 本番AC

class Solution {
    int INF = (int)(1e9);
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<unordered_set<int>> g(n);
        vector<int> deg(n);
        int m = relations.size();
        for (int i=0; i<m; ++i) {
            g[relations[i][0]-1].insert(relations[i][1]-1);
            deg[relations[i][1]-1]++;
        }
        vector<int> dist(n, INF);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
        for (int i=0; i<n; ++i) if (deg[i] == 0) {
            que.emplace(time[i], i);
            dist[i] = time[i];
        }
        while (!que.empty()) {
            auto [d, v] = que.top(); que.pop();
            auto ngi = g[v];
            for (int ti : g[v]) {
                deg[ti]--;
                ngi.erase(ti);
                if (deg[ti] == 0) {
                    int nd = d + time[ti];
                    dist[ti] = nd;
                    que.emplace(nd, ti);
                }
            }
            swap(g[v], ngi);
        }
        int res = 0;
        for (int i=0; i<n; ++i) res = max(res, dist[i]);
        return res;
    }
};
