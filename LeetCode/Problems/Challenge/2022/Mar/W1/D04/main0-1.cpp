// 自力1,WA

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        int val = 1;
        for (int i=0; i<100; ++i) {
            if (query_row == i) {
                if (poured >= val) return 1.0;
                else {
                    if (i <= 1) return (double)poured / val;
                    else {
                        int rval = (val - 1) * 2 + 2;
                        return (double)poured / rval * ((query_glass==0||query_glass==i) ? 1 : 2);
                    }
                }
            }
            if (poured < val) return 0.0;
            poured -= val;
            ++val;
        }
        return 1.0;
    }
};
