// 本番AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int n = nums.size(), res = 0;
        for (int i=0; i<n; ++i) {
            if (nums[i] > threshold) continue;
            int val = 1, li = i;
            if (nums[li]%2 == 0) res = max(res, i-li+1);
            while (li-1>=0 && nums[li-1]<=threshold && nums[li-1]%2!=nums[li]%2) {
                --li;
                if (nums[li]%2 == 0) res = max(res, i-li+1);
            }
        }
        return res;
    }
};
