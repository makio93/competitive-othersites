#include <bits/stdc++.h>
using namespace std;

// 自力AC

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size(), res = 0;
        for (int i=0; i<n; ++i) res ^= nums[i];
        return res;
    }
};
