// 解説AC1

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> vals(n, string(n, '.'));
        auto check = [&](int ri, int ci) -> bool {
            for (int i=ri-1; i>=0; --i) if (vals[i][ci] == 'Q') return false;
            for (int i=ri-1,j=ci-1; i>=0&&j>=0; --i,--j) if (vals[i][j] == 'Q') return false;
            for (int i=ri-1,j=ci+1; i>=0&&j<n; --i,++j) if (vals[i][j] == 'Q') return false;
            return true;
        };
        auto dfs = [&](auto dfs, int d=0) -> void {
            if (d == n) res.push_back(vals);
            else {
                for (int i=0; i<n; ++i) if (check(d, i)) {
                    vals[d][i] = 'Q';
                    dfs(dfs, d+1);
                    vals[d][i] = '.';
                }
            }
        };
        dfs(dfs);
        return res;
    }
};
