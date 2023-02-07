// 解説AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> glasses(query_row+1);
        glasses[0] = vector<double>(1, (double)poured);
        for (int i=0; i<query_row; ++i) {
            glasses[i+1] = vector<double>(i+2);
            for (int j=0; j<i+1; ++j) {
                double nval = max(0.0, glasses[i][j]-1.0);
                glasses[i+1][j] += nval / 2.0, glasses[i+1][j+1] += nval / 2.0;
            }
        }
        return min(1.0, glasses[query_row][query_glass]);
    }
};
