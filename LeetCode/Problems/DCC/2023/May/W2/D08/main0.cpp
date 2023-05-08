// 自力AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size(), res = 0;
        for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) if (i==j || i==n-1-j) res += mat[i][j];
        return res;
    }
};
