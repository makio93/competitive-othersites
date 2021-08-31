#include <bits/stdc++.h>
using namespace std;

// 自力AC

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if (n<2 || (n>=2&&nums[0]<nums[n-1])) return nums[0];
        else {
            int lid = 0, rid = n-1;
            while (rid-lid >= 2) {
                int cid = (lid + rid) / 2;
                if (nums[cid] < nums[rid]) rid = cid;
                else if (nums[cid] > nums[lid]) lid = cid;
            }
            return nums[rid];
        }
    }
};
