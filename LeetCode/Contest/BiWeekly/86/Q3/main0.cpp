// 本番AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumRows(vector<vector<int>>& mat, int cols) {
        int m = mat.size(), n = mat.front().size();
        int res = 0;
        for (int i=0; i<(1<<n); ++i) if (__builtin_popcount(i) == cols) {
            auto tmat = mat;
            for (int j=0; j<n; ++j) if ((i>>j)&1) {
                for (int ii=0; ii<m; ++ii) if (tmat[ii][j] == 1) tmat[ii][j] *= -1;
            }
            int cnt = 0;
            for (int j=0; j<m; ++j) if (count(tmat[j].begin(), tmat[j].end(), 1) == 0) ++cnt;
            res = max(res, cnt);
        }
        return res;
    }
};
