// 解説AC1

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size(), m = strs.front().length(), res = 0;
        vector<vector<int>> g(n);
        auto similar = [&](int li, int ri) -> bool {
            int cnt = 0;
            for (int i=0; i<m; ++i) if (strs[li][i] != strs[ri][i]) ++cnt;
            return cnt <= 2;
        };
        for (int i=0; i<n; ++i) for (int j=i+1; j<n; ++j) if (similar(i, j)) {
            g[i].push_back(j);
            g[j].push_back(i);
        }
        vector<bool> visited(n);
        auto dfs = [&](auto& dfs, int vi) -> void {
            visited[vi] = true;
            for (const int& ti : g[vi]) if (!visited[ti]) dfs(dfs, ti);
        };
        for (int i=0; i<n; ++i) if (!visited[i]) {
            dfs(dfs, i);
            ++res;
        }
        return res;
    }
};
