#include <bits/stdc++.h>
using namespace std;

// 自力AC1

class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) return false;
        long long val = 1;
        while (val<=(long long)n) {
            if (val == (long long)n) return true;
            val *= 3;
        }
        return false;
    }
};
