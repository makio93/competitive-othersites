// 自力AC2

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<bool> lcnt(2*n-1), rcnt(2*n-1), used(n);
        vector<string> vals(n, string(n, '.'));
        auto dfs = [&](auto dfs, int d=0) -> void {
            if (d == n) {
                res.push_back(vals);
                return;
            }
            for (int i=0; i<n; ++i) if (!used[i] && !lcnt[d+i] && !rcnt[d-i+n-1]) {
                used[i] = lcnt[d+i] = rcnt[d-i+n-1] = true;
                vals[d][i] = 'Q';
                dfs(dfs, d+1);
                vals[d][i] = '.';
                used[i] = lcnt[d+i] = rcnt[d-i+n-1] = false;
            }
        };
        dfs(dfs);
        return res;
    }
};
