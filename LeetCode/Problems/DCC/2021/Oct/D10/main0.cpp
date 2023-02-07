#include <bits/stdc++.h>
using namespace std;

// 自力AC

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int res = 0, xval = left & right;
        for (int i=0; i<=31; ++i) if ((xval>>i)&1) {
            if ((right^(1<<i)) < left) res |= (1<<i);
        }
        return res;
    }
};
