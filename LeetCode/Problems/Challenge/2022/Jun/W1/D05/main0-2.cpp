// 自力AC2

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalNQueens(int n) {
        int res = 0;
        vector<bool> lcnt(2*n-1), rcnt(2*n-1), used(n);
        auto dfs = [&](auto dfs, int d=0) -> void {
            if (d == n) {
                ++res;
                return;
            }
            for (int i=0; i<n; ++i) if (!used[i] && !lcnt[d+i] && !rcnt[d-i+n-1]) {
                used[i] = lcnt[d+i] = rcnt[d-i+n-1] = true;
                dfs(dfs, d+1);
                used[i] = lcnt[d+i] = rcnt[d-i+n-1] = false;
            }
        };
        dfs(dfs);
        return res;
    }
};
