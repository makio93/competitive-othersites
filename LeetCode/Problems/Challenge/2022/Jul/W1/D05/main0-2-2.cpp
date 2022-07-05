// 自力AC2-2,あんまり良くない

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        for (int& val : nums) val += (int)(1e9);
        vector<vector<int>> vlst((int)(1e5));
        int ri = 1;
        for (int i=0; i<2; ++i) {
            for (int& val : nums) vlst[val/ri%(int)(1e5)].push_back(val);
            int id = 0;
            for (auto& vi : vlst) for (int& val : vi) {
                nums[id] = val;
                ++id;
            }
            vlst = vector<vector<int>>((int)(1e5));
            if (i == 0) ri *= (int)(1e5);
        }
        int res = 0, cnt = 0, n = nums.size();
        for (int i=0; i<n; ++i) {
            if (i-1>=0 && nums[i]==nums[i-1]+1) ++cnt;
            else if (i-1<0 || nums[i]!=nums[i-1]) cnt = 1;
            res = max(res, cnt);
        }
        return res;
    }
};
