#include <bits/stdc++.h>
using namespace std;

// 自力AC,Time:O(n),Space:O(1)解法

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        for (int i=0; i<n; ++i) {
            if (nums[abs(nums[i])-1] > 0) nums[abs(nums[i])-1] *= -1;
            else res.push_back(abs(nums[i]));
        }
        return res;
    }
};
