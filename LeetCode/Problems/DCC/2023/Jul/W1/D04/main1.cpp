// 解説AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size(), x0 = 0, x1 = 0;
        for (int i=0; i<n; ++i) {
            x1 ^= x0 & nums[i];
            x0 ^= nums[i];
            int mask = ~(x0 & x1);
            x1 &= mask;
            x0 &= mask;
        }
        int res = 0;
        for (int i=0; i<32; ++i) if (x0>>i&1) res |= 1 << i;
        return res;
    }
};
