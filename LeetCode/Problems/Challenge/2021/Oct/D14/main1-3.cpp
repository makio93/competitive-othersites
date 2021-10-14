#include <bits/stdc++.h>
using namespace std;

// 解説AC3,数学的解法

class Solution {
    bool is_square(int n) {
        int r = (int)(sqrt(n));
        return (r*r == n);
    }
public:
    int numSquares(int n) {
        if (n <= 0) return 0;
        if (is_square(n)) return 1;
        while (n%4 == 0) n /= 4;
        if (n%8 == 7) return 4;
        for (int i=1; i*i<n; ++i) if (is_square(n-i*i)) return 2;
        return 3;
    }
};
