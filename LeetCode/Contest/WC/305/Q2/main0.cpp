// 本番AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        int m = restricted.size();
        vector<vector<int>> g(n);
        for (int i=0; i<n-1; ++i) {
            g[edges[i][0]].push_back(edges[i][1]);
            g[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool> rests(n);
        for (int i=0; i<m; ++i) rests[restricted[i]] = true;
        int res = 0;
        auto dfs = [&](auto dfs, int vi=0, int pi=-1) -> void {
            ++res;
            for (int ti : g[vi]) if (ti!=pi && !rests[ti]) dfs(dfs, ti, vi);
        };
        dfs(dfs);
        return res;
    }
};
