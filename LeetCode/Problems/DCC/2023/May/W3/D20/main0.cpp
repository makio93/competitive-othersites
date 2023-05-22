// 自力AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int m = equations.size(), q = queries.size();
        unordered_map<string, int> slst;
        for (int i=0; i<m; ++i) {
            if (slst.find(equations[i][0]) == slst.end()) slst[equations[i][0]] = slst.size();
            if (slst.find(equations[i][1]) == slst.end()) slst[equations[i][1]] = slst.size();
        }
        int n = slst.size();
        vector<unordered_map<int, double>> g(n);
        for (int i=0; i<m; ++i) {
            g[slst[equations[i][0]]][slst[equations[i][1]]] = 1.0 / values[i];
            g[slst[equations[i][1]]][slst[equations[i][0]]] = values[i];
        }
        vector<vector<double>> dists(n, vector<double>(n, -1.0));
        for (int i=0; i<n; ++i) {
            queue<int> que;
            dists[i][i] = 1.0;
            que.push(i);
            while (!que.empty()) {
                int vi = que.front(); que.pop();
                double di = dists[i][vi];
                for (const auto& pi : g[vi]) if (dists[i][pi.first] == -1.0) {
                    dists[i][pi.first] = di * pi.second;
                    que.push(pi.first);
                }
            }
        }
        vector<double> res(q, -1.0);
        for (int i=0; i<q; ++i) {
            if (slst.find(queries[i][0])!=slst.end() && slst.find(queries[i][1])!=slst.end()) 
                res[i] = dists[slst[queries[i][1]]][slst[queries[i][0]]];
        }
        return res;
    }
};
