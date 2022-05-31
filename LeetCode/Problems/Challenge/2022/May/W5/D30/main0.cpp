// 自力AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        bool neg = false;
        int bmx = 0, res = 0;
        if (dividend<0 || divisor<0) {
            if (dividend>=0 || divisor>=0) neg = true;
            if (dividend==1<<31 || divisor==1<<31) {
                if (dividend == divisor) return 1;
                else if (divisor == 1<<31) return 0;
                else if (divisor == 1) return 1<<31;
                else if (divisor == -1) return ~(1<<31);
                dividend += abs(divisor);
                ++res;
            }
            if (dividend < 0) dividend = -dividend;
            if (divisor < 0) divisor = -divisor;
        }
        while ((dividend>>bmx) >= divisor) ++bmx;
        for (int i=bmx-1; i>=0; --i) if (dividend >= (divisor<<i)) {
            dividend -= divisor << i;
            res += 1 << i;
        }
        if (neg) res = -res;
        return res;
    }
};
