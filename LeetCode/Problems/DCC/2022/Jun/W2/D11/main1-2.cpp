// 解説AC2

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size(), tsum = accumulate(nums.begin(), nums.end(), 0);
        int res = n+1, li = 0, ri = 0;
        while (ri >= li) {
            if (tsum >= x) {
                if (tsum == x) res = min(res, li+n-ri);
                if (ri < n) {
                    tsum -= nums[ri];
                    ++ri;
                }
                else break;
            }
            else {
                tsum += nums[li];
                ++li;
            }
        }
        if (res == n+1) res = -1;
        return res;
    }
};
