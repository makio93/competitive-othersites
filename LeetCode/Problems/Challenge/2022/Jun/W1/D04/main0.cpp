// 自力AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<int> ord(n);
        iota(ord.begin(), ord.end(), 0);
        vector<vector<string>> res;
        do {
            vector<string> vals(n, string(n, '.'));
            for (int i=0; i<n; ++i) vals[i][ord[i]] = 'Q';
            vector<int> lcnt(2*n-1), rcnt(2*n-1);
            for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) if (vals[i][j] == 'Q') {
                lcnt[i-j+n-1]++;
                rcnt[i+j]++;
            }
            bool ok = true;
            for (int i=0; i<2*n-1; ++i) if (lcnt[i] >= 2) ok = false;
            for (int i=0; i<2*n-1; ++i) if (rcnt[i] >= 2) ok = false;
            if (ok) res.push_back(vals);
        } while (next_permutation(ord.begin(), ord.end()));
        return res;
    }
};
