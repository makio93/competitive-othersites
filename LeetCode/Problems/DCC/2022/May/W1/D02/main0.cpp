// 自力AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size(), li = 0, ri = n - 1;
        while (li < ri) {
            while (li<ri && nums[li]%2==0) ++li;
            while (li<ri && nums[ri]%2==1) --ri;
            if (li < ri) swap(nums[li], nums[ri]);
        }
        return nums;
    }
};
