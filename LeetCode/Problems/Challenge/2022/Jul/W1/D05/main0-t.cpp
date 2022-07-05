// 自力AC-t,O(nlogn)解,禁止

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        sort(nums.begin(), nums.end());
        int res = 0, cnt = 0, n = nums.size();
        for (int i=0; i<n; ++i) {
            if (i-1>=0 && nums[i]==nums[i-1]+1) ++cnt;
            else if (i-1<0 || nums[i]!=nums[i-1]) cnt = 1;
            res = max(res, cnt);
        }
        return res;
    }
};
