// 解説AC2

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(int n) {
        return __builtin_popcount(n^(n*3));
    }
};
