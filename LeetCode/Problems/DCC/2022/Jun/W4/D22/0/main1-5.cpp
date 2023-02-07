// 解説AC5,分割統治

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size(), li = 0, ri = n-1;
        auto partial = [&]() -> int {
            int pivot = nums[li], l = li+1, r = ri;
            while (l <= r) {
                if (nums[l]<pivot && nums[r]>pivot) {
                    swap(nums[l], nums[r]);
                    ++l; --r;
                }
                while (l<=r && nums[l]>=pivot) ++l;
                while (l<=r && nums[r]<=pivot) --r;
            }
            swap(nums[li], nums[r]);
            return r;
        };
        while (1) {
            int id = partial();
            if (id == k-1) return nums[id];
            else if (id < k-1) li = id + 1;
            else ri = id - 1;
        }
    }
};
