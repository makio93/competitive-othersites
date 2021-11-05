#include <bits/stdc++.h>
using namespace std;

// 自力AC1

class Solution {
public:
    int arrangeCoins(int n) {
        long long r = (long long)round(sqrt(n*2LL));
        while (r*(r+1)/2 > (long long)n) --r;
        return (int)r;
    }
};
