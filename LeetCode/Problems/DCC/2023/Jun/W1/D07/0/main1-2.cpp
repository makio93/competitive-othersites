// 解説AC2

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minFlips(int a, int b, int c) {
        return __builtin_popcount((a|b)^c) + __builtin_popcount(a&b&((a|b)^c));
    }
};
