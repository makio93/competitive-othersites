// 自力AC

#include <bits/stdc++.h>
using namespace std;

const int INF = (int)(1e9);
class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        int m = connections.size();
        vector<vector<int>> g(n);
        for (int i=0; i<m; ++i) {
            g[connections[i][0]].push_back(connections[i][1]);
            g[connections[i][1]].push_back(connections[i][0]);
        }
        vector<int> ord(n, -1), low(n, INF);
        vector<vector<int>> bridges;
        auto dfs = [&](auto dfs, int vi=0, int pi=-1, int ki=0) -> int {
            ord[vi] = ki;
            low[vi] = ord[vi];
            ++ki;
            for (int ti : g[vi]) if (ti != pi) {
                if (ord[ti] == -1) {
                    ki = dfs(dfs, ti, vi, ki);
                    low[vi] = min(low[vi], low[ti]);
                }
                else low[vi] = min(low[vi], ord[ti]);
                if (ord[vi] < low[ti]) bridges.push_back(vector<int>({vi, ti}));
            }
            return ki;
        };
        dfs(dfs);
        return bridges;
    }
};
