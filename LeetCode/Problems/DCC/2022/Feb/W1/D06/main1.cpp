#include <bits/stdc++.h>
using namespace std;

// 解説AC

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size(), li = 1, ri = 1, cnt = 1;
        while (ri < n) {
            if (nums[ri-1] != nums[ri]) {
                nums[li] = nums[ri];
                ++li;
                cnt = 1;
            }
            else if (cnt < 2) {
                nums[li] = nums[ri];
                ++li;
                ++cnt;
            }
            ++ri;
        }
        return li;
    }
};
