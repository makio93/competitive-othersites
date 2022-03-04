// 自力4,WA

#include <bits/stdc++.h>
using namespace std;

static bool fil = false;
static vector<vector<double>> glasses;
class Solution {
    void pour(int m, int n, double poured) {
        if (m >= 100) return;
        double nval = min(poured, 1.0-glasses[m][n]);
        glasses[m][n] += nval;
        poured -= nval;
        if (poured == 0.0) return;
        pour(m+1, n, poured/2.0);
        pour(m+1, n+1, poured/2.0);
    }
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        if (!fil) {
            glasses = vector<vector<double>>(100, vector<double>(100));
            pour(query_row, query_glass, (double)1.);
            fil = true;
        }
        return glasses[query_row][query_glass];
    }
};
