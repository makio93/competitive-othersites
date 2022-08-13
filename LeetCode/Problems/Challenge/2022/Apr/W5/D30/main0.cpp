// 自力AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = equations.size(), m = queries.size();
        unordered_map<string, unordered_map<string, double>> g;
        for (int i=0; i<n; ++i) {
            g[equations[i][1]][equations[i][0]] = values[i];
            if (g[equations[i][0]].find(equations[i][1]) == g[equations[i][0]].end()) g[equations[i][0]][equations[i][1]] = 1.0 / values[i];
        }
        vector<double> res(m, -1.0);
        for (int i=0; i<m; ++i) {
            unordered_map<string, double> dist;
            queue<string> que;
            if (g.find(queries[i][1]) != g.end()) {
                que.push(queries[i][1]);
                dist[queries[i][1]] = 1.0;
            }
            while (!que.empty()) {
                string vi = que.front(); que.pop();
                double di = dist[vi];
                for (auto& tpi : g[vi]) if (dist.find(tpi.first) == dist.end()) {
                    double ndi = di * tpi.second;
                    que.push(tpi.first);
                    dist[tpi.first] = ndi;
                }
            }
            if (dist.find(queries[i][0]) != dist.end()) res[i] = dist[queries[i][0]];
        }
        return res;
    }
};
