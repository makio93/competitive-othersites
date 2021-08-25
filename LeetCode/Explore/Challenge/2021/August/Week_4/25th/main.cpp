#include <bits/stdc++.h>
using namespace std;

// 自力AC

class Solution {
public:
    bool judgeSquareSum(int c) {
        bool ok = false;
        for (long long a=0; a*a<=(long long)c/2; ++a) {
            long long b2 = c - a*a, b = sqrt(b2);
            while (b*b <= b2) {
                if (b*b == b2) ok = true;
                ++b;
            }
            if (ok) break;
        }
        return ok;
    }
};
