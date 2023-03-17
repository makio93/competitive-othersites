// 学習1回目,自力AC2

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mirrorReflection(int p, int q) {
        int pcnt = __builtin_ctz(p), qcnt = __builtin_ctz(q);
        if (pcnt > qcnt) return 2;
        else if (qcnt > pcnt) return 0;
        else return 1;
    }
};
