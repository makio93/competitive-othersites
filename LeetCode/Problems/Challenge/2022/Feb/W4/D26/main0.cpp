// 

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<unordered_set<int>> tg(n);
        for (int i=0; i<n; ++i) for (int tj : graph[i]) tg[i].insert(tj);
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        unordered_set<int> visited;
        pq.emplace(tg[0].size(), 0, -1);
        while (!pq.empty()) {
            auto pi = pq.top(); pq.pop();
            int vi = get<1>(pi), pvi = get<2>(pi);
            if (visited.find(vi)!=visited.end() || get<0>(pi)!=(int)(tg[vi].size())) continue;
            visited.insert(vi);
            if (pvi != -1) {
                tg[vi].insert(pvi);
                tg[pvi].insert(vi);
            }
            for (int ti : tg[vi]) if (visited.find(ti) == visited.end()) {
                if (tg[ti].find(vi) != tg[ti].end()) continue;
                tg[vi].erase(ti); tg[ti].erase(vi);
                pq.emplace(tg[ti].size(), ti, vi);
            }
        }
        vector<int> dist1(n, (int)(1e9)), dist2(n, (int)(1e9));
        queue<int> que;
        dist1[0] = 0;
        que.push(0);
        while (!que.empty()) {
            int vi = que.front(); que.pop();
            int di = dist1[vi];
            for (int ti : tg[vi]) if (dist1[ti] > di+1) {
                dist1[ti] = di+1;
                que.push(ti);
            }
        }
        pair<int, int> rpi1 = { -1, -1 }, rpi2 = { -1, -1 };
        for (int i=0; i<n; ++i) rpi1 = max(rpi1, { dist1[i], i });
        dist2[rpi1.second] = 0;
        que.push(rpi1.second);
        while (!que.empty()) {
            int vi = que.front(); que.pop();
            int di = dist2[vi];
            for (int ti : tg[vi]) if (dist2[ti] > di+1) {
                dist2[ti] = di+1;
                que.push(ti);
            }
        }
        for (int i=0; i<n; ++i) rpi2 = max(rpi2, { dist2[i], i });
        return (n-1)*2 - rpi2.first;
    }
};
