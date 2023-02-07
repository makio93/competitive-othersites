#include <bits/stdc++.h>
using namespace std;

// 自力AC

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size(), res = 0, ri = 0, val = 0;
        for (int li=0; li<n; ++li) {
            while (ri<n && (nums[ri]==1 || (nums[ri]==0&&val+1<=k))) {
                if (nums[ri] == 0) ++val;
                ++ri;
            }
            res = max(res, ri-li);
            if (nums[li] == 0) --val;
        }
        return res;
    }
};
