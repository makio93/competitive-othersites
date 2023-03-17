// 学習1回目,自力AC1

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mirrorReflection(int p, int q) {
        auto gcd = [&](auto gcd, int a, int b) -> int {
            if (a > b) return gcd(gcd, b, a);
            if (a == 0) return b;
            return gcd(gcd, a, b%a);
        };
        auto lcm = [&](int a, int b) -> int {
            return a / gcd(gcd, a, b) * b;
        };
        int lval = lcm(p, q);
        if (lval/p%2 == 0) return 0;
        else if (lval/q%2 == 0) return 2;
        else return 1;
    }
};
