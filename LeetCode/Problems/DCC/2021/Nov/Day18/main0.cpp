#include <bits/stdc++.h>
using namespace std;

// 自力AC

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        for (int i=0; i<n; ++i) if (nums[abs(nums[i])-1] > 0) nums[abs(nums[i])-1] *= -1;
        vector<int> res;
        for (int i=0; i<n; ++i) if (nums[i] > 0) res.push_back(i+1);
        return res;
    }
};
