#include <bits/stdc++.h>
using namespace std;

// 解説AC,Space:O(1)解

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix.front().size();
        bool zero = false;
        for (int j=0; j<m; ++j) if (matrix[0][j] == 0) zero = true;
        for (int j=0; j<m; ++j) {
            bool zero2 = false;
            for (int i=0; i<n; ++i) if (matrix[i][j] == 0) zero2 = true;
            if (zero2) matrix[0][j] = 0;
        }
        for (int i=1; i<n; ++i) {
            bool zero2 = false;
            for (int j=0; j<m; ++j) if (matrix[i][j] == 0) zero2 = true;
            if (zero2) matrix[i][0] = 0;
        }
        for (int i=1; i<n; ++i) if (matrix[i][0] == 0) for (int j=1; j<m; ++j) matrix[i][j] = 0;
        for (int j=0; j<m; ++j) if (matrix[0][j] == 0) for (int i=1; i<n; ++i) matrix[i][j] = 0;
        if (zero) for (int j=0; j<m; ++j) matrix[0][j] = 0;
    }
};
