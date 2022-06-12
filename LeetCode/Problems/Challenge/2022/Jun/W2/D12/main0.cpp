// 自力AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size(), mval = 0;
        for (int vi : nums) mval = max(mval, vi);
        vector<bool> used(mval+1);
        int res = 0, val = 0, li = 0;
        for (int i=0; i<n; ++i) {
            while (used[nums[i]]) {
                val -= nums[li];
                used[nums[li]] = false;
                ++li;
            }
            val += nums[i];
            used[nums[i]] = true;
            res = max(res, val);
        }
        return res;
    }
};
