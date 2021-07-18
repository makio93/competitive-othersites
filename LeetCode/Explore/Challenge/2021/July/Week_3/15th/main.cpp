#include <bits/stdc++.h>
using namespace std;

// 自力AC

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int res = 0;
        for (int i=0; i<n; ++i) for (int j=i+1; j<n; ++j) {
            int d1 = lower_bound(nums.begin(), nums.end(), nums[i]+nums[j]) - nums.begin();
            int d2 = upper_bound(nums.begin(), nums.end(), nums[j]-nums[i]) - nums.begin();
            res += max(0, d1 - max(j+1, d2));
        }
        return res;
    }
};
