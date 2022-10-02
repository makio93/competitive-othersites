// 本番AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int bcnt = __builtin_popcount(num2), res = 0;
        for (int i=29; i>=0; --i) {
            if (bcnt == 0) break;
            if (num1&(1<<i)) {
                res |= (1<<i);
                --bcnt;
            }
        }
        for (int i=0; i<30; ++i) {
            if (bcnt == 0) break;
            if (!(res&(1<<i))) {
                res |= (1<<i);
                --bcnt;
            }
        }
        return res;
    }
};
