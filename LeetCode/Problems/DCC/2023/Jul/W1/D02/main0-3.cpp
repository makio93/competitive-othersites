// 自力WA3

#include <bits/stdc++.h>
using namespace std;

const int INF = (int)(1e9);
class Solution {
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        int m = requests.size();
        vector<unordered_map<int, int>> g(n);
        int scnt = 0;
        for (int i=0; i<m; ++i) {
            if (requests[i][0] == requests[i][1]) ++scnt;
            else g[requests[i][0]][requests[i][1]]++;
        }
        vector<bool> visited(n);
        function<int(int, int, int)> dfs = [&](int vi, int si, int di) {
            if (visited[vi]) return 0;
            visited[vi] = true;
            int rval = 0, dval = di;
            for (auto& tpi : g[vi]) if (tpi.second > 0) {
                if (tpi.first == si) {
                    int sval = min(dval, tpi.second);
                    tpi.second -= sval;
                    dval -= sval;
                    rval += sval;
                }
                else {
                    int sval = min(dval, dfs(tpi.first, si, min(di, tpi.second)));
                    tpi.second -= sval;
                    dval -= sval;
                    rval += sval;
                }
            }
            visited[vi] = false;
            return rval;
        };
        bool br = false;
        while (!br) {
            br = true;
            for (int i=0; i<n; ++i) if (dfs(i, i, INF) > 0) br = false;
        }
        int res = 0;
        for (int i=0; i<n; ++i) for (const auto& pi : g[i]) res += pi.second;
        return (m - scnt) - res + scnt;
    }
};
