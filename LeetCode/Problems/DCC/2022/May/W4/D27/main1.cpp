// 解説AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSteps(int num) {
        return num ? __builtin_popcount(num) + 31 - __builtin_clz(num) : 0;
    }
};
