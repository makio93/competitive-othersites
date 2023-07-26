// 学習1回目,解説AC1

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n));
        int val = 1;
        for (int i=0; i<n/2; ++i) {
            for (int j=i; j<n-i-1; ++j) res[i][j] = val++;
            for (int j=i; j<n-i-1; ++j) res[j][n-i-1] = val++;
            for (int j=n-i-1; j>i; --j) res[n-i-1][j] = val++;
            for (int j=n-i-1; j>i; --j) res[j][i] = val++;
        }
        if (n%2 == 1) res[n/2][n/2] = val;
        return res;
    }
};
