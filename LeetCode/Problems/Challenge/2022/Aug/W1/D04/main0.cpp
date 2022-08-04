// 自力AC

#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) { return (b ? gcd(b, a%b) : a); }
class Solution {
public:
    int mirrorReflection(int p, int q) {
        int g = gcd(p, q);
        p /= g; q /= g;
        if (q%2 == 0) return 0;
        else if (p%2 == 0) return 2;
        else return 1;
    }
};
