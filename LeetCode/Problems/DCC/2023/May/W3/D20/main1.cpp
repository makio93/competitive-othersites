// 解説AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = equations.size(), q = queries.size();
        unordered_map<string, unordered_map<string, double>> g;
        for (int i=0; i<n; ++i) {
            g[equations[i][1]][equations[i][0]] = values[i];
            g[equations[i][0]][equations[i][1]] = 1.0 / values[i];
        }
        function<double(string,string,unordered_set<string>&)> dfs = [&](string start, string target, unordered_set<string>& visited) {
            if (g.find(start) == g.end()) return -1.0;
            visited.insert(start);
            if (start == target) return 1.0;
            for (const auto& tpi : g[start]) if (visited.find(tpi.first) == visited.end()) {
                auto tval = dfs(tpi.first, target, visited);
                if (tval != -1.0) return tval * tpi.second;
            }
            return -1.0;
        };
        vector<double> res(q, -1.0);
        unordered_set<string> visited;
        for (int i=0; i<q; ++i) {
            visited.clear();
            res[i] = dfs(queries[i][1], queries[i][0], visited);
        }
        return res;
    }
};
