// 自力AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> g;
    vector<int> colors;
    bool dfs(int vi, int col=1) {
        colors[vi] = col;
        int tcol = -col;
        for (int ti : g[vi]) {
            if (colors[ti] == 0) { if (!dfs(ti, tcol)) return false; }
            else if (colors[ti] != tcol) return false;
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        g = graph;
        colors.assign(n, 0);
        for (int i=0; i<n; ++i) if (colors[i] == 0) if (!dfs(i)) return false;
        return true;
    }
};
