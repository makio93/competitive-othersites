#include <bits/stdc++.h>
using namespace std;

// 自力AC,Time:(N),Space:(N),題意に沿わない計算量

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> vals;
        for (int i=0; i<n; ++i) {
            if (vals.find(nums[i]) == vals.end()) vals.insert(nums[i]);
            else vals.erase(nums[i]);
        }
        vector<int> res;
        for (int val : vals) res.push_back(val);
        return res;
    }
};
