// 学習1回目,解説4

#include <bits/stdc++.h>
using namespace std;

class Solution {
    void heapify(vector<int>& nums, int id, int n) {
        int ti = id, left = id*2+1, right = id*2+2;
        if (left<n && nums[left]>nums[ti]) ti = left;
        if (right<n && nums[right]>nums[ti]) ti = right;
        if (ti != id) {
            swap(nums[id], nums[ti]);
            heapify(nums, ti, n);
        }
    }
    void make_heap(vector<int>& nums, int n) {
        for (int i=n/2-1; i>=0; --i) heapify(nums, i, n);
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size(), res = 0, hlen = n;
        make_heap(nums, hlen);
        for (int i=0; i<k-1; ++i) {
            swap(nums[0], nums[hlen-1]);
            --hlen;
            heapify(nums, 0, hlen);
        }
        return nums[0];
    }
};
