// 自力AC3

#include <bits/stdc++.h>
using namespace std;

static vector<int> memo(1<<8, -1);
class Solution {
    int bcnt(unsigned int val) {
        if (memo[val] == -1) {
            memo[val] = 0;
            for (int i=0; i<8; ++i) memo[val] += (val >> i) & 1;
        }
        return memo[val];
    }
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        for (int i=0; i<4; ++i) res += bcnt((n>>(i*8))&((1<<8)-1));
        return res;
    }
};
