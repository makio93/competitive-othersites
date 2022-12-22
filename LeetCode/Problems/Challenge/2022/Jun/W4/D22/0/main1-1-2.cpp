// 解説AC1-2,nth_element

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        nth_element(nums.rbegin(), nums.rend()-k, nums.rend());
        return nums[k-1];
    }
};
