#include <bits/stdc++.h>
using namespace std;

// 自力AC

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size(), res = 0;
        for (int i=0; i<n; ++i) if (nums[i] == 0) nums[i] = -1;
        for (int i=0; i+1<n; ++i) nums[i+1] += nums[i];
        unordered_map<int, int> vcnt;
        vcnt[0] = -1;
        for (int i=0; i<n; ++i) {
            if (vcnt.find(nums[i]) == vcnt.end()) vcnt[nums[i]] = i;
            else res = max(res, i-vcnt[nums[i]]);
        }
        return res;
    }
};
