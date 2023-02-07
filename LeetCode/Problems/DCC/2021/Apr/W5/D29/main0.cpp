#include <bits/stdc++.h>
using namespace std;

// 自力AC

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> res = { -1, -1 };
        if (!nums.empty()) {
            int li = distance(nums.begin(), lower_bound(nums.begin(), nums.end(), target)), 
                ri = distance(nums.begin(), upper_bound(nums.begin(), nums.end(), target));
            if (ri-li > 0) res = { li, ri-1 };
        }
        return res;
    }
};
