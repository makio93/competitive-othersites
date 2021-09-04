#include <bits/stdc++.h>
using namespace std;

// 自力AC

class Solution {
    const int INF = (int)(1e9);
    vector<vector<int>> g;
    vector<int> rval, rdist, ssize;
    int dfs1(int v=0, int p=-1) {
        int res = 1;
        for (int t : g[v]) if (t != p) res += dfs1(t, v);
        return (ssize[v] = res);
    }
    void dfs2(int v=0, int p=-1) {
        int val = rval[v];
        for (int t : g[v]) if (t != p) {
            rval[t] = val - ssize[t] + ((int)(g.size()) - ssize[t]);
            dfs2(t, v);
        }
    }
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        rval = vector<int>(n);
        rdist = vector<int>(n, INF);
        ssize = vector<int>(n);
        g = vector<vector<int>>(n);
        for (int i=0; i<n-1; ++i) {
            g[edges[i][0]].push_back(edges[i][1]);
            g[edges[i][1]].push_back(edges[i][0]);
        }
        queue<int> que;
        que.push(0);
        rdist[0] = 0;
        while (!que.empty()) {
            int v = que.front(); que.pop();
            int d = rdist[v], nd = d + 1;
            for (int t : g[v]) {
                if (rdist[t] <= nd) continue;
                que.push(t);
                rdist[t] = nd;
            }
        }
        for (int i=0; i<n; ++i) rval[0] += rdist[i];
        dfs1();
        dfs2();
        return rval;
    }
};
