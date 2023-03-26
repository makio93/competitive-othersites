// 自力AC

#include <bits/stdc++.h>
using namespace std;

const int INF = (int)(1e9);
class Solution {
public:
    int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {
        int n = coins.size();
        if (count(coins.begin(), coins.end(), 1) <= 1) return 0;
        vector<vector<int>> g(n);
        for (int i=0; i<n-1; ++i) {
            g[edges[i][0]].push_back(edges[i][1]);
            g[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> dist1(n, INF), dist2(n, INF);
        int sid1 = find(coins.begin(), coins.end(), 1) - coins.begin();
        queue<int> que;
        dist1[sid1] = 0;
        que.push(sid1);
        while (!que.empty()) {
            int vi = que.front(); que.pop();
            int di = dist1[vi], ndi = di + 1;
            for (const int& ti : g[vi]) if (dist1[ti] > ndi) {
                dist1[ti] = ndi;
                que.push(ti);
            }
        }
        pair<int, int> mval = { -1, -1 };
        for (int i=0; i<n; ++i) if (coins[i] == 1) mval = max(mval, { dist1[i], i });
        int si = mval.second;
        dist2[si] = 0;
        que.push(si);
        while (!que.empty()) {
            int vi = que.front(); que.pop();
            int di = dist2[vi], ndi = di + 1;
            for (const int& ti : g[vi]) if (dist2[ti] > ndi) {
                dist2[ti] = ndi;
                que.push(ti);
            }
        }
        mval = { -1, -1 };
        for (int i=0; i<n; ++i) if (coins[i] == 1) mval = max(mval, { dist2[i], i });
        int tar = mval.second;
        vector<int> vlst;
        auto dfs0 = [&](auto dfs0, int vi, int pi=-1) -> bool {
            vlst.push_back(vi);
            if (vi == tar) return true;
            for (const int& ti : g[vi]) if (ti != pi) {
                if (dfs0(dfs0, ti, vi)) return true;
            }
            vlst.pop_back();
            return false;
        };
        dfs0(dfs0, si);
        int slen = vlst.size(), ci = vlst[slen/2];
        vector<int> par(n, -INF);
        auto dfs1 = [&](auto dfs1, int vi, int pi=-1) -> bool {
            bool ok = coins[vi] == 1;
            for (const int& ti : g[vi]) if (ti != pi) {
                if (dfs1(dfs1, ti, vi)) ok = true;
            }
            if (ok) par[vi] = pi;
            return ok;
        };
        dfs1(dfs1, ci);
        vector<bool> check(n);
        for (int i=0; i<n; ++i) if (coins[i] == 1) {
            int vi = i;
            for (int j=0; j<2; ++j) {
                if (par[vi] < 0) break;
                vi = par[vi];
            }
            check[vi] = true;
        }
        vector<bool> visited(n);
        auto dfs2 = [&](auto dfs2, int vi, int pi=-1) -> bool {
            bool ok = check[vi];
            for (const int& ti : g[vi]) if (ti != pi) {
                if (dfs2(dfs2, ti, vi)) ok = true;
            }
            if (ok) visited[vi] = true;
            return ok;
        };
        dfs2(dfs2, ci);
        int res = 0;
        for (int i=0; i<n-1; ++i) if (visited[edges[i][0]] && visited[edges[i][1]]) ++res;
        return res * 2;
    }
};
