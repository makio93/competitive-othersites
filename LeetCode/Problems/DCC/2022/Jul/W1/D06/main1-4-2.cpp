// 解説AC4-2

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int fib(int n) { return round(pow((sqrt(5) + 1) / 2, n) / sqrt(5)); }
};
