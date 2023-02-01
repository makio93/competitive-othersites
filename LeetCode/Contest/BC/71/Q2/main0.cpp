#include <bits/stdc++.h>
using namespace std;

// 本番AC

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> vals1, vals2, vals3, res;
        for (int i=0; i<n; ++i) {
            if (nums[i] < pivot) vals1.push_back(nums[i]);
            else if (nums[i] == pivot) vals2.push_back(nums[i]);
            else vals3.push_back(nums[i]);
        }
        for (int val : vals1) res.push_back(val);
        for (int val : vals2) res.push_back(val);
        for (int val : vals3) res.push_back(val);
        return res;
    }
};
