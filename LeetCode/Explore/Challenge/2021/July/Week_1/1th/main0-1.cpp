#include <bits/stdc++.h>
using namespace std;

// 自力TLE

class Solution {
    vector<vector<int>> g;
    vector<bool> visited;
    vector<int> ord;
    bool dfs(int v=0) {
        visited[v] = true;
        ord.push_back(v);
        bool res = false;
        if (ord.size() == g.size()) { for (int t : g[v]) if (t == 0) { res = true; break; } }
        else { for (int t : g[v]) if (!visited[t] && dfs(t)) { res = true; break; } }
        if (!res) ord.pop_back();
        visited[v] = false;
        return res;
    }
public:
    vector<int> grayCode(int n) {
        g = vector<vector<int>>(1<<n);
        for (int i=0; i<(1<<n); ++i) {
            for (int j=0; j<n; ++j) {
                g[i].push_back(i^(1<<j));
                g[i^(1<<j)].push_back(i);
            }
        }
        visited = vector<bool>(1<<n);
        ord = vector<int>();
        dfs();
        return ord;
    }
};
