// 自力AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        for (int i=1; i<n; ++i) nums[0] ^= nums[i] ^ i;
        return nums[0] ^ n;
    }
};
