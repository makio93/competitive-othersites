// 解説AC1-2

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int n = nums.size(), mval = (int)(2e9), res = (int)(2e9);
        for (int i=0; i<n; ++i) {
            if (nums[i]%2 == 1) nums[i] *= 2;
            mval = min(mval, nums[i]);
        }
        make_heap(nums.begin(), nums.end());
        while (nums.front()%2 == 0) {
            res = min(res, nums.front()-mval);
            mval = min(mval, nums.front()/2);
            pop_heap(nums.begin(), nums.end());
            nums.back() /= 2;
            push_heap(nums.begin(), nums.end());
        }
        return min(res, nums.front()-mval);
    }
};
