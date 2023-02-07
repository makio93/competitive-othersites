// 

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int fib(int n) {
        if (n <= 1) return n;
        int p0 = 0, p1 = 1;
        for (int i=2; i<=n; ++i) {
            int np = p1 + p0;
            p0 = p1;
            p1 = np;
        }
        return p1;
    }
};
