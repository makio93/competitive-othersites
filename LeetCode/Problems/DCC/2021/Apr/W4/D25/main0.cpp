#include <bits/stdc++.h>
using namespace std;

// 自力AC

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i=0; i<n/2; ++i) for (int j=0; j<(n+1)/2; ++j) {
            vector<int> ti = { i, j, n-1-i, n-1-j }, tj = { j, n-1-i, n-1-j, i };
            int tval = matrix[i][j];
            for (int i2=0; i2<4; ++i2) {
                int ni = ti[(i2+1)%4], nj = tj[(i2+1)%4];
                swap(tval, matrix[ni][nj]);
            }
        }
    }
};
