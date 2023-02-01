#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int len = original.size();
        if (len != m*n) return vector<vector<int>>(0);
        vector<vector<int>> res(m, vector<int>(n));
        for (int i=0; i<m; ++i) for (int j=0; j<n; ++j) res[i][j] = original[i*n+j];
        return res;
    }
};
