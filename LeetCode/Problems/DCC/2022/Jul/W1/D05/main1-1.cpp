// 解説AC1:O(nlogn)解

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        sort(nums.begin(), nums.end());
        int res = 1, cur = 1;
        for (int i=1; i<n; ++i) if (nums[i] != nums[i-1]) {
            if (nums[i] == nums[i-1]+1) ++cur;
            else {
                res = max(res, cur);
                cur = 1;
            }
        }
        res = max(res, cur);
        return res;
    }
};
