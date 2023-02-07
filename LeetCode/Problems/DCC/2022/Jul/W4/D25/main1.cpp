// 解説AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> res(2, -1);
        int li = -1, ri = n;
        while (ri-li > 1) {
            int ci = (li+ri) / 2;
            if (nums[ci] < target) li = ci;
            else ri = ci;
        }
        if (ri>=n || nums[ri]>target) return res;
        res[0] = ri;
        ri = n;
        while (ri-li > 1) {
            int ci = (li+ri) / 2;
            if (nums[ci] > target) ri = ci;
            else li = ci;
        }
        res[1] = li;
        return res;
    }
};
