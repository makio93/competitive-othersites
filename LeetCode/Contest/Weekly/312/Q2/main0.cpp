// 本番AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size(), mval = *max_element(nums.begin(), nums.end());
        int res = 1, cnt = 0;
        for (int i=0; i<n; ++i) {
            if (nums[i] == mval) ++cnt;
            else cnt = 0;
            res = max(res, cnt);
        }
        return res;
    }
};
