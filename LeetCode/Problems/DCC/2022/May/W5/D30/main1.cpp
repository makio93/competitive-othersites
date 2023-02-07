// 解説AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
class Solution {
public:
    int divide(int dividend, int divisor) {
        bool neg = (dividend >= 0) ^ (divisor >= 0);
        ll ta = llabs(dividend), tb = llabs(divisor);
        ll res = 0, tmp = 0;
        while (ta >= tb) {
            while (ta >= tb<<(tmp+1)) ++tmp;
            ta -= tb << tmp;
            res += 1LL << tmp;
            tmp = 0;
        }
        if (neg) res = -res;
        res = min(res, (ll)INT_MAX);
        return (int)res;
    }
};
