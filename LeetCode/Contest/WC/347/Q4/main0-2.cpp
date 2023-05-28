// 本番WA2

#include <bits/stdc++.h>
using namespace std;

const vector<int> di = { -1, 0, 1, 0 }, dj = { 0, 1, 0, -1 };
class Solution {
public:
    int maxIncreasingCells(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat.front().size();
        vector<map<int, unordered_set<int>>> rtoc(m), ctor(n);
        for (int i=0; i<m; ++i) for (int j=0; j<n; ++j) rtoc[i][mat[i][j]].insert(i*n+j);
        for (int i=0; i<n; ++i) for (int j=0; j<m; ++j) ctor[i][mat[j][i]].insert(j*n+i);
        priority_queue<pair<int, int>> pq;
        vector<int> dist(m*n);
        for (int i=0; i<m; ++i) {
            for (const int& si : rtoc[i].begin()->second) {
                pq.emplace(1, si);
                dist[si] = 1;
                ctor[si%n][rtoc[i].begin()->first].erase(si);
            }
            rtoc[i].erase(rtoc[i].begin());
        }
        for (int i=0; i<n; ++i) {
            for (const int& si : ctor[i].begin()->second) {
                pq.emplace(1, si);
                dist[si] = 1;
                rtoc[si/n][ctor[i].begin()->first].erase(si);
            }
            ctor[i].erase(ctor[i].begin());
        }
        while (!pq.empty()) {
            auto [di, id] = pq.top(); pq.pop();
            if (dist[id] != di) continue;
            int ndi = di + 1, ri = id / n, ci = id % n, val = mat[ri][ci];
            auto ritr = rtoc[ri].upper_bound(val);
            if (ritr != rtoc[ri].end()) {
                int nval = ritr->first;
                for (const int& ti : ritr->second) {
                    if (dist[ti] < ndi) {
                        dist[ti] = ndi;
                        pq.emplace(ndi, ti);
                    }
                    ctor[ci][nval].erase(ti);
                    if (ctor[ci][nval].empty()) ctor[ci].erase(nval);
                }
                rtoc[ri].erase(ritr);
            }
            auto citr = ctor[ci].upper_bound(val);
            if (citr != ctor[ci].end()) {
                int nval = citr->first;
                for (const int& ti : citr->second) {
                    if (dist[ti] < ndi) {
                        dist[ti] = ndi;
                        pq.emplace(ndi, ti);
                    }
                    rtoc[ri][nval].erase(ti);
                    if (rtoc[ri][nval].empty()) rtoc[ri].erase(nval);
                }
                ctor[ci].erase(citr);
            }
        }
        int res = 0;
        for (int i=0; i<m; ++i) for (int j=0; j<n; ++j) res = max(res, dist[i*n+j]);
        return res;
    }
};
