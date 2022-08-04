// 解説AC2

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mirrorReflection(int p, int q) {
        return 1 + ((q&-q)<(p&-p)) - ((p&-p)<(q&-q));
    }
};
