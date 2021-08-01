#include <bits/stdc++.h>
using namespace std;

// 自力AC

class Solution {
    const int NINF = (int)(-1e9);
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix.front().size(), res = NINF;
        vector<vector<int>> csum(n, vector<int>(m+1));
        for (int i=0; i<n; ++i) for (int j=1; j<=m; ++j) csum[i][j] += csum[i][j-1] + matrix[j-1][i];
        for (int i=0; i<m; ++i) for (int j=i+1; j<=m; ++j) {
            int sum = 0;
            set<int> sst = { 0 };
            for (int r=0; r<n; ++r) {
                sum += csum[r][j] - csum[r][i];
                auto itr = sst.lower_bound(sum-k);
                if (itr != sst.end()) res = max(res, sum-(*itr));
                sst.insert(sum);
            }
        }
        return res;
    }
};
