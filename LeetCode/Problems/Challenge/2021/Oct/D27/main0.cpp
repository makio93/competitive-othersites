#include <bits/stdc++.h>
using namespace std;

// 自力AC,Time:O(n),Space:O(1)解法

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int lid = 0, rid = n-1;
        while (lid<n && nums[lid]==0) ++lid;
        while (rid>=0 && nums[rid]==2) --rid;
        for (int i=lid; i<=rid; ++i) {
            if (nums[i] == 0) { swap(nums[lid], nums[i]); ++lid; }
            else if (nums[i] == 2) { swap(nums[rid], nums[i]); --rid; --i; }
        }
    }
};
