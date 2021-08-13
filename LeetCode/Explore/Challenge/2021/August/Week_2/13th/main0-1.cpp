#include <bits/stdc++.h>
using namespace std;

// 自力AC1,Space:O(N+M)解

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix.front().size();
        vector<int> rows(n), cols(m);
        for (int i=0; i<n; ++i) for (int j=0; j<m; ++j) if (matrix[i][j] == 0) { rows[i]++; cols[j]++; }
        for (int i=0; i<n; ++i) if (rows[i] > 0) for (int j=0; j<m; ++j) matrix[i][j] = 0;
        for (int j=0; j<m; ++j) if (cols[j] > 0) for (int i=0; i<n; ++i) matrix[i][j] = 0;
    }
};
