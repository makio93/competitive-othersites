// 自力AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colors(n);
        function<bool(int,int)> dfs = [&](int vi, int ci) -> bool {
            colors[vi] = ci;
            for (const int& ti : graph[vi]) {
                if (colors[ti] == -ci) continue;
                if (colors[ti] == ci || !dfs(ti, -ci)) return false;
            }
            return true;
        };
        for (int i=0; i<n; ++i) if (colors[i] == 0 && !dfs(i, 1)) return false;
        return true;
    }
};
