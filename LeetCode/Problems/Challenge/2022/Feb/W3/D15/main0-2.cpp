#include <bits/stdc++.h>
using namespace std;

// 自力AC,手直し

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        for (int i=0; i<n-1; ++i) nums[i+1] ^= nums[i];
        return nums[n-1];
    }
};
