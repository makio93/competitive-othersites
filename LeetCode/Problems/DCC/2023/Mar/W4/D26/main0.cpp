// 自力AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size(), res = -1;
        vector<int> searching(n, -1);
        vector<bool> finished(n);
        function<void(int,int,int)> dfs = [&](int vi, int pi, int di) {
            searching[vi] = di;
            int ndi = di + 1;
            if (edges[vi] != -1 && !finished[edges[vi]]) {
                if (searching[edges[vi]] != -1) res = max(res, ndi - searching[edges[vi]]);
                else dfs(edges[vi], vi, ndi);
            }
            finished[vi] = true;
        };
        for (int i=0; i<n; ++i) if (!finished[i]) dfs(i, -1, 0);
        return res;
    }
};
