// 自力AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
class NumMatrix {
    vector<vector<ll>> sums;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        sums = vector<vector<ll>>(matrix.size()+1, vector<ll>(matrix.front().size()+1));
        for (int i=0; i<matrix.size(); ++i) for (int j=0; j<matrix.front().size(); ++j) 
            sums[i+1][j+1] = matrix[i][j] + sums[i][j+1] + sums[i+1][j] - sums[i][j];
    }
    int sumRegion(int row1, int col1, int row2, int col2) {
        return sums[row2+1][col2+1] - sums[row2+1][col1] - sums[row1][col2+1] + sums[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
