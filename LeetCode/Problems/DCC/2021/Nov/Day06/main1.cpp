#include <bits/stdc++.h>
using namespace std;

// 解説AC,Time:(N),Space:(1)

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        long long mask = 0;
        for (int i=0; i<n; ++i) mask ^= nums[i];
        mask &= -mask;
        int val1 = 0, val2 = 0;
        for (int i=0; i<n; ++i) {
            if (mask&nums[i]) val1 ^= nums[i];
            else val2 ^= nums[i];
        }
        vector<int> res({ val1, val2 });
        return res;
    }
};
