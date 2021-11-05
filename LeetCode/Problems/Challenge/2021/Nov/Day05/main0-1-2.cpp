#include <bits/stdc++.h>
using namespace std;

// 自力AC1-2

class Solution {
public:
    int arrangeCoins(int n) {
        unsigned r = (unsigned)sqrt((unsigned)n*2UL);
        while ((r*(r+1UL)+1UL)/2UL > (unsigned)n) --r;
        return r;
    }
};
