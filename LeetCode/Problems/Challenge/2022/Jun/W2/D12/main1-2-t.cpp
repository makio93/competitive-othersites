// 計算量削減

#include <bits/stdc++.h>
using namespace std;

static bitset<10001> used;
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int res = 0, val = 0, li = 0;
        for (int i=0; i<n; ++i) {
            while (used[nums[i]]) {
                val -= nums[li];
                used[nums[li]] = false;
                ++li;
            }
            val += nums[i];
            used[nums[i]] = true;
            res = max(res, val);
        }
        used.reset();
        return res;
    }
};
