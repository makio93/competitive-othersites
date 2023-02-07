#include <bits/stdc++.h>
using namespace std;

// 自力AC,橋検出

class Solution {
    vector<vector<int>> g;
    vector<int> ord, low;
    set<pair<int, int>> brid;
    void dfs(int vi, int pi=-1, int di=0) {
        if (ord[vi] == (int)(1e9)) {
            ord[vi] = low[vi] = di;
            for (int ti : g[vi]) if (ti != pi) {
                if (ord[ti] == (int)(1e9)) {
                    dfs(ti, vi, di+1);
                    low[vi] = min(low[vi], low[ti]);
                    if (ord[vi] < low[ti]) {
                        int ai = vi, bi = ti;
                        if (ai > bi) swap(ai, bi);
                        brid.emplace(ai, bi);
                    }
                }
                else low[vi] = min(low[vi], ord[ti]);
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        int m = connections.size();
        g = vector<vector<int>>(n);
        for (int i=0; i<m; ++i) {
            g[connections[i][0]].push_back(connections[i][1]);
            g[connections[i][1]].push_back(connections[i][0]);
        }
        ord = vector<int>(n, (int)(1e9));
        low = vector<int>(n, (int)(1e9));
        dfs(0);
        vector<vector<int>> res;
        for (int i=0; i<m; ++i) {
            int ai = connections[i][0], bi = connections[i][1];
            if (ai > bi) swap(ai, bi);
            if (brid.find({ai, bi}) != brid.end()) res.push_back(connections[i]);
        }
        return res;
    }
};
