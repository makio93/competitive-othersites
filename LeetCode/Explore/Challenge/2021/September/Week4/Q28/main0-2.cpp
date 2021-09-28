#include <bits/stdc++.h>
using namespace std;

// 自力AC,Space:O(1)

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n = nums.size(), eid = 0, oid = 1;
        while (eid<n && oid<n) {
            while (eid<n && nums[eid]%2==0) eid += 2;
            while (oid<n && nums[oid]%2==1) oid += 2;
            if (eid>=n || oid>=n) break;
            swap(nums[eid], nums[oid]);
        }
        return nums;
    }
};
