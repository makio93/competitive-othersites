// 学習1回目,自力AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = equations.size(), m = queries.size();
        unordered_map<string, unordered_map<string, double>> g;
        for (int i=0; i<n; ++i) {
            g[equations[i][0]][equations[i][1]] = values[i];
            g[equations[i][1]][equations[i][0]] = 1.0 / values[i];
        }
        vector<double> res(m, -1.0);
        unordered_set<string> visited;
        for (int i=0; i<m; ++i) if (g.find(queries[i][0])!=g.end() && g.find(queries[i][1])!=g.end()) {
            auto dfs = [&](auto dfs, string vi, string tar, double val=1.0) -> double {
                if (vi == tar) return val;
                visited.insert(vi);
                for (const auto& tpi : g[vi]) if (visited.find(tpi.first) == visited.end()) {
                    double ret = dfs(dfs, tpi.first, tar, val*tpi.second);
                    if (ret >= -0.5) return ret;
                }
                return -1.0;
            };
            res[i] = dfs(dfs, queries[i][0], queries[i][1]);
            visited.clear();
        }
        return res;
    }
};
