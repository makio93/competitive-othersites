// 自力AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1.0;
        if (n == 1<<31) {
            double tmp = myPow(x, n / 2);
            return tmp * tmp;
        }
        if (n < 0) return 1.0 / myPow(x, -n);
        double res = 1.0;
        while (n) {
            if (n % 2 == 1) res *= x;
            x *= x;
            n /= 2;
        }
        return res;
    }
};
