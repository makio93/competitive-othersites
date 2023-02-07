// 解説AC2-2,partial_sort

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        partial_sort(nums.rbegin(), nums.rend()-k+1, nums.rend());
        return nums[k-1];
    }
};
