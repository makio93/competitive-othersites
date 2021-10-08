#include <bits/stdc++.h>
using namespace std;

// 解説AC,Space:O(1)解2

class Solution {
public:
    int climbStairs(int n) {
        int b = 1, a = 0;
        while (n--) a = (b += a) - a;
        return b;
    }
};
