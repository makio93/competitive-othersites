#include <bits/stdc++.h>
using namespace std;

// 自力WA2-1,Space:O(1)解

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix.front().size();
        for (int i=0; i<n; ++i) for (int j=0; j<m; ++j) {
            if (matrix[i][j] == 0) { if (i-1<0 || (i-1>=0&&matrix[i-1][j]!=0)) for (int i2=0; i2<n; ++i2) matrix[i2][j] = 0; }
            else {
                bool zero = false;
                for (int j2=0; j2<m; ++j2) if (matrix[i][j2]==0 && (i-1<0||(i-1>=0&&matrix[i-1][j2]!=0))) zero = true;
                if (zero) {
                    matrix[i][j] = 0;
                    if (i+1<n && matrix[i+1][j]==0) for (int i2=0; i2<n; ++i2) matrix[i2][j] = 0;
                }
            }
        }
    }
};
