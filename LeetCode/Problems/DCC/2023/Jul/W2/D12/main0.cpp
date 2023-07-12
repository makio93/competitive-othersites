// 

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> searching(n), finished(n), unsafes(n);
        function<int(int)> dfs = [&](int vi) {
            searching[vi] = true;
            int rval = -1;
            for (const int& ti : graph[vi]) {
                if (unsafes[ti]) {
                    unsafes[vi] = true;
                    rval = -1;
                    break;
                }
                if (finished[ti]) continue;
                if (searching[ti]) {
                    rval = ti;
                    if (rval == vi) rval = -1;
                    unsafes[vi] = true;
                    break;
                }
                rval = dfs(ti);
                if (unsafes[ti]) {
                    if (rval == vi) rval = -1;
                    unsafes[vi] = true;
                    break;
                }
            }
            searching[vi] = false;
            finished[vi] = true;
            return rval;
        };
        for (int i=0; i<n; ++i) if (!finished[i]) dfs(i);
        vector<int> res;
        for (int i=0; i<n; ++i) if (!unsafes[i]) res.push_back(i);
        return res;
    }
};
