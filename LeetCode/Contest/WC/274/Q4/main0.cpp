#include <bits/stdc++.h>
using namespace std;

// 本番中+後,自力WA

class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();
        vector<unordered_set<int>> g(n), g2(n);
        for (int i=0; i<n; ++i) {
            g[i].insert(favorite[i]);
            g[favorite[i]].insert(i);
        }
        vector<bool> visited(n), visited2(n), searching(n);
        vector<unordered_set<int>> roops;
        unordered_set<int> dlst;
        function<bool(int,int)> dfs = [&](int vi, int pi) -> bool {
            if (searching[vi]) {
                roops.back().insert(vi);
                return true;
            }
            bool res = false;
            searching[vi] = true;
            for (int ti : g[vi]) if (ti!=pi && !visited[ti] && dfs(ti, vi) && roops.back().find(vi)==roops.back().end()) res = true;
            if (res) roops.back().insert(vi);
            searching[vi] = false;
            visited[vi] = true;
            dlst.insert(vi);
            return res;
        };
        for (int i=0; i<n; ++i) if (!visited[i]) {
            roops.push_back(unordered_set<int>({}));
            dfs(i, -1);
            if (roops.back().empty()) {
                for (int vi : dlst) {
                    g2[vi].insert(favorite[vi]);
                    g2[favorite[vi]].insert(vi);
                }
            }
            else for (int vi : dlst) visited2[vi] = true;
            dlst.clear();
        }
        int res1 = 0, res2 = 0;
        for (int i=0; i<(int)(roops.size()); ++i) res1 = max(res1, (int)(roops[i].size()));
        for (int i=0; i<n; ++i) if (!visited2[i]) {
            unordered_map<int, int> dist, dist2;
            queue<int> que;
            que.push(i);
            dist[i] = 0;
            while (!que.empty()) {
                int vi = que.front(); que.pop();
                int di = dist[vi], ndi = di + 1;
                if (g2[vi].empty()) continue;
                for (int ti : g2[vi]) if (!visited2[ti]) {
                    if (dist.find(ti) != dist.end()) continue;
                    dist[ti] = ndi;
                    que.push(ti);
                }
            }
            pair<int, int> mval = { -1, -1 };
            for (auto pval : dist) mval = max(mval, { pval.second, pval.first });
            que.push(mval.second);
            dist2[mval.second] = 0;
            visited2[mval.second] = true;
            while (!que.empty()) {
                int vi = que.front(); que.pop();
                int di = dist2[vi], ndi = di + 1;
                if (g2[vi].empty()) continue;
                for (int ti : g[vi]) {
                    if (visited2[ti] || dist2.find(ti)!=dist2.end()) continue;
                    dist2[ti] = ndi;
                    que.push(ti);
                    visited2[ti] = true;
                }
            }
            pair<int, int> mval2 = { -1, -1 };
            for (auto pval : dist2) mval2 = max(mval2, { pval.second, pval.first });
            res2 += mval2.first + 1;
        }
        return max(res1, res2);
    }
};
