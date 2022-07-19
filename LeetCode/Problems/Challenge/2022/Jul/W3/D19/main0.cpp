// 自力AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res(numRows);
        res[0] = vector<int>(1, 1);
        for (int i=1; i<numRows; ++i) {
            for (int j=0; j<=i; ++j) {
                res[i].push_back((j-1>=0?res[i-1][j-1]:0)+(j<=i-1?res[i-1][j]:0));
            }
        }
        return res;
    }
};
