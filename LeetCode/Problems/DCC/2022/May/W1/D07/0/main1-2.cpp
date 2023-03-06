// 解説AC2

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        vector<int> mvals(n);
        mvals[0] = nums[0];
        for (int i=1; i<n; ++i) mvals[i] = min(mvals[i-1], nums[i]);
        int id = n;
        for (int i=n-1; i>=1; --i) {
            if (nums[i] <= mvals[i-1]) continue;
            auto itr = upper_bound(nums.begin()+id, nums.end(), mvals[i-1]);
            if (itr!=nums.end() && *itr<nums[i]) return true;
            id = itr - nums.begin() - 1;
            nums[id] = nums[i];
        }
        return false;
    }
};
