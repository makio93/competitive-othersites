// 解説AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size(), zcnt = 0, ri = 0, res = 0;
        for (int li=0; li<n; ++li) {
            while (ri<n && (zcnt<1 || (zcnt<=1 && nums[ri]==1))) {
                if (nums[ri] == 0) ++zcnt;
                ++ri;
            }
            res = max(res, ri-li-1);
            if (nums[li] == 0) --zcnt;
        }
        return res;
    }
};
