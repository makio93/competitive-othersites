// 解説AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
    unordered_map<string, unordered_set<string>> g;
    unordered_map<string, double> vals, dist;
    double dfs(string ver, string tar, double val) {
        dist[ver] = val;
        if (ver == tar) return val;
        for (const string& nxt : g[ver]) if (dist.find(nxt) == dist.end()) {
            double rval = dfs(nxt, tar, val*vals[ver+"->"+nxt]);
            if (rval != -1.0) return rval;
        }
        return -1.0;
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = equations.size(), m = queries.size();
        for (int i=0; i<n; ++i) {
            g[equations[i][0]].insert(equations[i][1]);
            g[equations[i][1]].insert(equations[i][0]);
            vals[equations[i][0]+"->"+equations[i][1]] = values[i];
            vals[equations[i][1]+"->"+equations[i][0]] = 1.0 / values[i];
        }
        vector<double> res(m);
        for (int i=0; i<m; ++i) {
            dist.clear();
            if (g.find(queries[i][0])==g.end() || g.find(queries[i][1])==g.end()) res[i] = -1.0;
            else res[i] = dfs(queries[i][0], queries[i][1], 1.0);
        }
        return res;
    }
};
