#include <bits/stdc++.h>
using namespace std;

// 自力AC

class Solution {
public:
    int hammingDistance(int x, int y) { return __builtin_popcount(x^y); }
};
