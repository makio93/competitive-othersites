#include <bits/stdc++.h>
using namespace std;

// 解説AC,STLを使用

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        partial_sum(nums.begin(), nums.end(), nums.begin());
        return nums;
    }
};
