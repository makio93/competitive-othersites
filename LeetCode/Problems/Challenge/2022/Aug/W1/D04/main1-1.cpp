// 解説AC1

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mirrorReflection(int p, int q) {
        while (p%2==0 && q%2==0) { p /= 2; q /= 2; }
        return 1 + q%2 - p%2;
    }
};
