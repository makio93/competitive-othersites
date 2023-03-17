// 学習1回目,自力AC2

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mirrorReflection(int p, int q) {
        if ((p&-p) > (q&-q)) return 2;
        else if ((q&-q) > (p&-p)) return 0;
        else return 1;
    }
};
