// 解説AC3

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> vals(n, string(n, '.'));
        ll flag = 0;
        auto dfs = [&](auto dfs, int d=0) -> void {
            if (d == n) res.push_back(vals);
            else {
                for (int i=0; i<n; ++i) if (!((flag>>i)&1) && !((flag>>(n+d+i))&1) && !((flag>>(4*n-2+d-i))&1)) {
                    flag |= 1LL<<i; flag |= 1LL<<(n+d+i); flag |= 1LL<<(4*n-2+d-i);
                    vals[d][i] = 'Q';
                    dfs(dfs, d+1);
                    vals[d][i] = '.';
                    flag &= ~(1LL<<i); flag &= ~(1LL<<(n+d+i)); flag &= ~(1LL<<(4*n-2+d-i));
                }
            }
        };
        dfs(dfs);
        return res;
    }
};
