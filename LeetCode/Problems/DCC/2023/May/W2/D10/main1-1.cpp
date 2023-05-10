// 解説AC1

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n));
        int yi = 0, xi = 0, len = n - 1, val = 1;
        for (int di=0; di<=(n-1)/2; ++di) {
            yi = di, xi = di;
            if (len == 0) res[yi][xi] = val++;
            else {
                for (int i=0; i<len; ++i) res[yi][xi++] = val++;
                for (int i=0; i<len; ++i) res[yi++][xi] = val++;
                for (int i=0; i<len; ++i) res[yi][xi--] = val++;
                for (int i=0; i<len; ++i) res[yi--][xi] = val++;
            }
            len -= 2;
        }
        return res;
    }
};
