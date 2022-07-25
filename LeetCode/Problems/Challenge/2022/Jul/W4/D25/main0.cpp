// 自力AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int li = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int ri = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        vector<int> res(2, -1);
        if (li!=n && nums[li]==target) {
            res[0] = li;
            res[1] = ri - 1;
        }
        return res;
    }
};
