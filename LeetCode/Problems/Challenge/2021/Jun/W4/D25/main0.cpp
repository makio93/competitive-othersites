#include <bits/stdc++.h>
using namespace std;

// 自力AC

class Solution {
    bool dfs(vector<vector<pair<int, int>>>& g, int& mid, vector<bool>& visited, int& rv, int v=0, int p=-1) {
        if (visited[v]) {
            rv = v;
            return true;
        }
        bool res = false;
        visited[v] = true;
        for (auto pi : g[v]) if (pi.first!=p && dfs(g, mid, visited, rv, pi.first, v)) {
            mid = max(mid, pi.second);
            if (v != rv) res = true;
        }
        visited[v] = false;
        return res;
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<pair<int, int>>> g(n);
        for (int i=0; i<n; ++i) {
            g[edges[i][0]-1].emplace_back(edges[i][1]-1, i);
            g[edges[i][1]-1].emplace_back(edges[i][0]-1, i);
        }
        vector<bool> visited(n);
        int mid = -1, rv = -1;
        dfs(g, mid, visited, rv);
        return edges[mid];
    }
};
