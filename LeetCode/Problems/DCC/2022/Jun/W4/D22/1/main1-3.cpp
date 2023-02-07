// 学習1回目,解説3

#include <bits/stdc++.h>
using namespace std;

class Solution {
    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[left], li = left + 1, ri = right;
        while (ri-li >= 0) {
            if (nums[li]<pivot && nums[ri]>pivot) {
                swap(nums[li], nums[ri]);
                ++li, --ri;
            }
            else {
                if (nums[li] >= pivot) ++li;
                if (nums[ri] <= pivot) --ri;
            }
        }
        swap(nums[left], nums[ri]);
        return ri;
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size(), li = 0, ri = n-1;
        while (ri-li >= 1) {
            int ki = partition(nums, li, ri);
            if (ki == k-1) li = ri = ki;
            else if (ki < k-1) li = ki + 1;
            else ri = ki - 1;
        }
        return nums[li];
    }
};
