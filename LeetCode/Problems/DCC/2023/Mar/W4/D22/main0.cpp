// 自力AC

#include <bits/stdc++.h>
using namespace std;

const int INF = (int)(1e9);
class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        int m = roads.size();
        vector<vector<pair<int, int>>> g(n);
        for (int i=0; i<m; ++i) {
            int ai = roads[i][0], bi = roads[i][1], di = roads[i][2];
            --ai; --bi;
            g[ai].emplace_back(bi, di);
            g[bi].emplace_back(ai, di);
        }
        int res = INF;
        vector<bool> visited(n);
        function<void(int, int)> dfs = [&](int vi, int pi) {
            visited[vi] = true;
            for (const auto& [ti, tdi] : g[vi]) if (ti != pi) {
                res = min(res, tdi);
                if (visited[ti]) continue;
                dfs(ti, vi);
            }
        };
        dfs(0, -1);
        return res;
    }
};
