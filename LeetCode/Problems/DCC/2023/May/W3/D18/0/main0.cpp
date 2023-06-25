// 自力AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        int m = edges.size();
        vector<vector<int>> g(n);
        for (int i=0; i<m; ++i) g[edges[i][0]].push_back(edges[i][1]);
        vector<bool> checked(n), visited(n);
        function<void(int)> dfs = [&](int vi) {
            visited[vi] = true;
            for (const auto& ti : g[vi]) {
                if (visited[ti]) {
                    if (checked[ti]) checked[ti] = false;
                    continue;
                }
                dfs(ti);
            }
        };
        for (int i=0; i<n; ++i) if (!visited[i]) {
            dfs(i);
            checked[i] = true;
        }
        vector<int> res;
        for (int i=0; i<n; ++i) if (checked[i]) res.push_back(i);
        return res;
    }
};
