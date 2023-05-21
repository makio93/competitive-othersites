// 本番WA

#include <bits/stdc++.h>
using namespace std;

const int INF = (int)(2.1e9), VMAX = (int)(2e9);
class Solution {
public:
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        int m = edges.size();
        vector<set<pair<int, int>>> g(n);
        for (int i=0; i<m; ++i) {
            g[edges[i][0]].emplace(edges[i][1], edges[i][2]);
            g[edges[i][1]].emplace(edges[i][0], edges[i][2]);
        }
        vector<int> dist0(n, INF);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.emplace(0, source);
        dist0[source] = 0;
        while (!pq.empty()) {
            auto pi = pq.top(); pq.pop();
            int vi = pi.second, di = pi.first;
            if (dist0[vi] != di) continue;
            for (const auto& tpi : g[vi]) if (tpi.second != -1) {
                int ndi = di + tpi.second, nvi = tpi.first;
                if (dist0[nvi] <= ndi) continue;
                dist0[nvi] = ndi;
                pq.emplace(ndi, nvi);
            }
        }
        vector<vector<int>> res;
        if (dist0[destination] < target) return res;
        else if (dist0[destination] == target) {
            res = edges;
            for (int i=0; i<m; ++i) if (res[i][2] == -1) res[i][2] = VMAX;
            return res;
        }
        vector<int> dist1(n, INF), pre(n, -1);
        pq.emplace(0, source);
        dist1[source] = 0;
        while (!pq.empty()) {
            auto pi = pq.top(); pq.pop();
            int vi = pi.second, di = pi.first;
            if (dist1[vi] != di) continue;
            for (const auto& tpi : g[vi]) {
                int ndi = di + (tpi.second == -1 ? 0 : tpi.second), nvi = tpi.first;
                if (dist1[nvi] <= ndi) continue;
                dist1[nvi] = ndi;
                pre[nvi] = vi;
                pq.emplace(ndi, nvi);
            }
        }
        set<pair<int, int>> est;
        int vi = destination;
        while (pre[vi] != -1) {
            int ai = pre[vi], bi = vi;
            if (ai > bi) swap(ai, bi);
            if (g[ai].find(make_pair(bi, -1)) != g[ai].end()) est.emplace(ai, bi);
            vi = pre[vi];
        }
        if (dist1[destination]+(int)(est.size()) > target) return res;
        int sub = target - dist1[destination], sval = sub - (int)(est.size()) + 1;
        res = edges;
        for (int i=0; i<m; ++i) if (res[i][2] == -1) {
            int ai = res[i][0], bi = res[i][1];
            if (ai > bi) swap(ai, bi);
            if (est.find({ai, bi}) != est.end()) {
                if (est.find({ai, bi}) == est.begin()) res[i][2] = sval;
                else res[i][2] = 1;
            }
            else res[i][2] = VMAX;
        }
        return res;
    }
};
