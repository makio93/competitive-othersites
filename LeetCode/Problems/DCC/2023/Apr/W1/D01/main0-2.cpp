// 自力AC2

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size(), li = 0, ri = n-1;
        while (ri-li >= 0) {
            int ci = (li + ri) / 2;
            if (nums[ci] < target) li = ci + 1;
            else if (nums[ci] > target) ri = ci - 1;
            else return ci;
        }
        return -1;
    }
};
