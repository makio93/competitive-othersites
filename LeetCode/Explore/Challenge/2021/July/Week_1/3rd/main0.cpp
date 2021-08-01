#include <bits/stdc++.h>
using namespace std;

// 自力TLE

class Solution {
    const int NINF = (int)(-1e9);
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix.front().size(), res = NINF;
        vector<vector<int>> sum(m+1, vector<int>(n+1));
        for (int i=1; i<=m; ++i) for (int j=1; j<=n; ++j) {
            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + matrix[i-1][j-1];
            for (int i2=0; i2<i; ++i2) for (int j2=0; j2<j; ++j2) {
                int val = sum[i][j] - sum[i2][j] - sum[i][j2] + sum[i2][j2];
                if (val <= k) res = max(res, val);
            }
        }
        return res;
    }
};