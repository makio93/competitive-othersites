#include <bits/stdc++.h>
using namespace std;

// 自力AC

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res(numRows);
        res[0] = vector<int>({1});
        for (int i=1; i<numRows; ++i) {
            res[i] = vector<int>(i+1);
            for (int j=0; j<i; ++j) {
                res[i][j] += res[i-1][j];
                res[i][j+1] += res[i-1][j];
            }
        }
        return res;
    }
};
