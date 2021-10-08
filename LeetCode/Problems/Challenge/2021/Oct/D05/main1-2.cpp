#include <bits/stdc++.h>
using namespace std;

// 解説AC,Space:O(1)解

class Solution {
public:
    int climbStairs(int n) {
        int val = 1, pval = 0;
        while (n--) {
            val += pval;
            pval = val - pval;
        }
        return val;
    }
};
