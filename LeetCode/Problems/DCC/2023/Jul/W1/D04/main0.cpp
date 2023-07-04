// 自力AC(制約上は失格)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size(), res = 0;
        vector<int> bcnt(32);
        for (int i=0; i<n; ++i) for (int j=0; j<32; ++j) if (nums[i]>>j&1) bcnt[j]++;
        for (int i=0; i<32; ++i) if (bcnt[i] % 3) res |= 1<<i;
        return res;
    }
};
