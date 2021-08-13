#include <bits/stdc++.h>
using namespace std;

// 自力AC2-2,Space:O(1)解

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix.front().size(), memo = -1;
        for (int i=0; i<n; ++i) {
            bool zero = false;
            for (int j=0; j<m; ++j) if(matrix[i][j] == 0) zero = true;
            if (zero) {
                memo = i;
                break;
            }
        }
        if (memo != -1) {
            for (int i=0; i<n; ++i) if (i != memo) {
                bool zero = false;
                for (int j=0; j<m; ++j) if (matrix[i][j] == 0) {
                    matrix[memo][j] = 0;
                    zero = true;
                }
                if (zero) for (int j=0; j<m; ++j) matrix[i][j] = 0;
            }
            for (int j=0; j<m; ++j) {
                if (matrix[memo][j] == 0) { for (int i=0; i<n; ++i) matrix[i][j] = 0; }
                else matrix[memo][j] = 0;
            }
        }
    }
};
