// 自力解答,WA

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        priority_queue<pair<int, int>> pq;
        vector<int> dist1(n, (int)(1e9)), dist2(n, (int)(1e9));
        vector<int> deg1(n), deg2;
        for (int i=0; i<n; ++i) deg1[i] = graph[i].size();
        deg2 = deg1;
        dist1[0] = 0, deg1[0]--;
        pq.emplace(0, 0);
        while (!pq.empty()) {
            auto pi = pq.top(); pq.pop();
            int vi = pi.second, di = dist1[vi];
            if (di != pi.first) continue;
            deg1[vi]--;
            for (int ti : graph[vi]) if (dist1[ti]==(int)(1e9) || (dist1[ti]<di+1&&deg1[vi]>=0&&deg1[ti]>=0)) {
                dist1[ti] = di+1, deg1[ti]--;
                pq.emplace(di+1, ti);
            }
        }
        pair<int, int> rpi = { -1, -1 }, rpi2 = { -1, -1 };
        for (int i=0; i<n; ++i) rpi = max(rpi, { dist1[i], i });
        dist2[rpi.second] = 0, deg2[rpi.second]--;
        pq.emplace(0, rpi.second);
        while (!pq.empty()) {
            auto pi = pq.top(); pq.pop();
            int vi = pi.second, di = dist2[vi];
            if (di != pi.first) continue;
            deg2[vi]--;
            for (int ti : graph[vi]) if (dist2[ti]==(int)(1e9) || (dist2[ti]<di+1&&deg2[vi]>=0&&deg2[ti]>=0)) {
                dist2[ti] = di+1, deg2[ti]--;
                pq.emplace(di+1, ti);
            }
        }
        for (int i=0; i<n; ++i) rpi2 = max(rpi2, { dist2[i], i });
        return (n-1)*2 - rpi2.first;
    }
};
