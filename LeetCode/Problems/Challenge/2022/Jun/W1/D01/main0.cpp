// 自力AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n = nums.size();
        for (int i=0; i<n-1; ++i) nums[i+1] += nums[i];
        return nums;
    }
};
