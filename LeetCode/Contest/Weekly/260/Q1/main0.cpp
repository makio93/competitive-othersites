#include <bits/stdc++.h>
using namespace std;

// 本番AC

class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size(), mval = nums[0], res = -1;
        for (int i=1; i<n; ++i) {
            if (nums[i] > mval) res = max(res, nums[i]-mval);
            mval = min(mval, nums[i]);
        }
        return res;
    }
};
