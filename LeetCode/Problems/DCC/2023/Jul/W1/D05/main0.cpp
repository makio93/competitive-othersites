// 

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> vlst;
        vlst.emplace_back(nums[0], 1);
        for (int i=1; i<n; ++i) {
            if (vlst.back().first == nums[i]) vlst.back().second++;
            else vlst.emplace_back(nums[i], 1);
        }
        if (vlst.front().first == 1 && vlst.front().second == n) return n - 1;
        int res = 0, m = vlst.size();
        for (int i=0; i<m; ++i) if (vlst[i].first == 1) res = max(res, vlst[i].second);
        for (int i=1; i<m-1; ++i) if (vlst[i].first == 0 && vlst[i].second == 1) res = max(res, vlst[i-1].second+vlst[i+1].second);
        return res;
    }
};
