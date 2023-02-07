// 解説AC4

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int fib(int n) {
        static double phi = (sqrt(5) + 1) / 2;
        return (int)round(pow(phi, n) / sqrt(5));
    }
};
