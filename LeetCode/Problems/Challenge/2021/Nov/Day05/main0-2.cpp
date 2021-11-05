#include <bits/stdc++.h>
using namespace std;

// 自力AC2

class Solution {
public:
    int arrangeCoins(int n) {
        int res = 0;
        for (int i=1; i/2*(i+1)<=n; ++i) {
            res += i;
            if (res > n-(i+1)) return i;
        }
        return 0;
    }
};
