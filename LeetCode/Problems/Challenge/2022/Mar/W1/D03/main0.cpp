// 自力AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size(), res = 0, cnt = 0;
        for (int i=0; i<n; ++i) {
            if (i-2>=0 && nums[i-1]-nums[i-2]==nums[i]-nums[i-1]) {
                ++cnt;
                if (i+1>=n || nums[i]-nums[i-1]!=nums[i+1]-nums[i]) res += cnt * (cnt+1) / 2;
            }
            else cnt = 0;
        }
        return res;
    }
};
