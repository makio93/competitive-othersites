#include <bits/stdc++.h>
using namespace std;

// 解説AC1,O(N^3)

const int INF = (int)(1e9);

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int n = matrix.size(), m = matrix.front().size();
        if (m == 0) return 0;
        vector<vector<int>> bcnt(n+1, vector<int>(m+1));
        for (int i=0; i<n; ++i) for (int j=0; j<m; ++j) if (matrix[i][j] == '1') bcnt[i+1][j+1] = bcnt[i+1][j] + 1;
        int res = 0;
        for (int i=1; i<=n; ++i) for (int j=1; j<=m; ++j) {
            int mval = INF;
            for (int h=i; h>0; --h) {
                mval = min(mval, bcnt[h][j]);
                if (mval == 0) break;
                res = max(res, mval*(i-h+1));
            }
        }
        return res;
    }
};
