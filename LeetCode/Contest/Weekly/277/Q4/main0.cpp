#include <bits/stdc++.h>
using namespace std;

// 本番AC

class Solution {
public:
    int maximumGood(vector<vector<int>>& statements) {
        int n = statements.size(), res = 0;
        for (int i=0; i<(1<<n); ++i) {
            bool ok = true;
            for (int j=0; j<n; ++j) if ((i>>j)&1) {
                for (int j2=0; j2<n; ++j2) if (statements[j][j2] != 2) {
                    if (statements[j][j2]==0 && ((i>>j2)&1)) ok = false;
                    if (statements[j][j2]==1 && !((i>>j2)&1)) ok = false;
                }
            }
            if (ok) res = max(res, (int)__builtin_popcount(i));
        }
        return res;
    }
};
