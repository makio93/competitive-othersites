#include <bits/stdc++.h>
using namespace std;

// 自力AC

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size(), nval = (int)(-1e9), rlen = 0, vcnt = 0, res = 0;
        for (int i=0; i+rlen<n; ++i) {
            nums[i] = nums[i+rlen];
            if (nval != nums[i]) {
                nval = nums[i];
                vcnt = 1;
            }
            else {
                ++vcnt;
                if (vcnt >= 2) while (i+rlen+1<n && nums[i+rlen+1]==nval) ++rlen;
            }
            res = max(res, i+1);
        }
        return res;
    }
};
