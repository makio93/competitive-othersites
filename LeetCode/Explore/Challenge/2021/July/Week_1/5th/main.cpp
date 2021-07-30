#include <bits/stdc++.h>
using namespace std;

// 自力AC

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size(), n = mat.front().size();
        if (r*c != m*n) return mat;
        vector<vector<int>> res(r, vector<int>(c));
        for (int i=0; i<m*n; ++i) res[i/c][i%c] = mat[i/n][i%n];
        return res;
    }
};
