// 自力AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, bool>>> g(n);
        for (int i=0; i<n-1; ++i) {
            g[connections[i][0]].emplace_back(connections[i][1], true);
            g[connections[i][1]].emplace_back(connections[i][0], false);
        }
        int res = 0;
        function<void(int, int)> dfs = [&](int vi, int pi) {
            for (const auto& [ti, is] : g[vi]) if (ti != pi) {
                if (is) ++res;
                dfs(ti, vi);
            }
        };
        dfs(0, -1);
        return res;
    }
};
