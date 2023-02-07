// 自力3,WA

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        if (poured < query_row+1) return 0.0;
        double res = 1.0;
        for (int i=0; i<query_row; ++i) res /= 2.0;
        for (int i=1; i<=query_glass; ++i) res *= (double)(query_row-i+1);
        for (int i=1; i<=query_glass; ++i) res /= (double)i;
        res = min(res*(poured/(query_row+1)), 1.0);
        return res;
    }
};
