#include <bits/stdc++.h>
using namespace std;

// 解説AC2,Time:(N),Space:(1)

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size(), xval = 0, mask = 0;
        for (int i=0; i<n; ++i) xval ^= nums[i];
        mask = xval & -(long long)xval;
        int val1 = 0;
        for (int i=0; i<n; ++i) if (mask&nums[i]) val1 ^= nums[i];
        vector<int> res({ val1, xval^val1 });
        return res;
    }
};
