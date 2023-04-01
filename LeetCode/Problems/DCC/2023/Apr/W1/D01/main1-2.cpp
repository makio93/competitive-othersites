// 解説AC2

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size(), li = 0, ri = n;
        while (ri-li > 0) {
            int ci = (li + ri) / 2;
            if (nums[ci] <= target) li = ci + 1;
            else ri = ci;
        }
        if (li-1>=0 && nums[li-1]==target) return li - 1;
        else return -1;
    }
};
