#include <bits/stdc++.h>
using namespace std;

// 自力AC

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n-1;
        while (r-l > 0) {
            int c = l + (r-l) / 2;
            if (c%2 == 0) {
                if (nums[c] == nums[c+1]) l = c+1;
                else r = c;
            }
            else {
                if (nums[c] == nums[c+1]) r = c;
                else l = c+1;
            }
        }
        return nums[l];
    }
};
