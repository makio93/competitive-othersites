// 本番TLE

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalSteps(vector<int>& nums) {
        int n = nums.size();
        vector<int> pnums;
        int res = 0;
        while (1) {
            pnums.push_back(nums[0]);
            for (int i=1; i<n; ++i) {
                if (nums[i-1] <= nums[i]) pnums.push_back(nums[i]);
            }
            if (pnums.size() < nums.size()) {
                ++res;
                swap(pnums, nums);
                pnums.clear();
                n = nums.size();
            }
            else break;
        }
        return res;
    }
};
