// 本番WA

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalSteps(vector<int>& nums) {
        int n = nums.size();
        int li = 0, ri = 1, cnt = 0, pre = -1;
        int res = 0;
        while (ri < n) {
            while (ri<n && nums[ri]<nums[li]) {
                if (nums[ri] >= pre) ++cnt;
                pre = max(pre, nums[ri]);
                ++ri;
            }
            res = max(res, cnt);
            cnt = 0;
            pre = -1;
            li = ri;
            ri = li + 1;
        }
        return res;
    }
};
