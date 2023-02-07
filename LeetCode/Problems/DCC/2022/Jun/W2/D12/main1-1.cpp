// 解説AC1

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> used;
        int res = 0, val = 0, li = 0;
        for (int i=0; i<n; ++i) {
            while (used.find(nums[i]) != used.end()) {
                val -= nums[li];
                used.erase(nums[li]);
                ++li;
            }
            val += nums[i];
            used.insert(nums[i]);
            res = max(res, val);
        }
        return res;
    }
};
