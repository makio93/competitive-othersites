// 解説AC3

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        nth_element(nums.begin(), nums.begin()+(n/2), nums.end());
        int res = 0;
        for (int& vi : nums) res += abs(vi-nums[n/2]);
        return res;
    }
};
