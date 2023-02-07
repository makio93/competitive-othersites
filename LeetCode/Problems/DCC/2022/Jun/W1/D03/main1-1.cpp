// 解説AC

#include <bits/stdc++.h>
using namespace std;

class NumMatrix {
    vector<vector<int>> sums;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        sums = vector<vector<int>>(matrix.size(), vector<int>(matrix.front().size()+1));
        for (int i=0; i<matrix.size(); ++i) for (int j=0; j<matrix.front().size(); ++j) sums[i][j+1] += matrix[i][j] + sums[i][j];
    }
    int sumRegion(int row1, int col1, int row2, int col2) {
        int res = 0;
        for (int i=row1; i<=row2; ++i) res += sums[i][col2+1] - sums[i][col1];
        return res;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
