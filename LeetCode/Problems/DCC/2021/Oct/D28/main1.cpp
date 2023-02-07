#include <bits/stdc++.h>
using namespace std;

// 解説AC,O(N*N)解法

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (int i=0; i<n; ++i) {
            int li = i+1, ri = n-1, tar = -nums[i];
            while (li < ri) {
                if (tar > nums[li]+nums[ri]) ++li;
                else if (tar < nums[li]+nums[ri]) --ri;
                else {
                    vector<int> trip = { nums[i], nums[li], nums[ri] };
                    res.push_back(trip);
                    while (li<ri && nums[li]==trip[1]) ++li;
                    while (li<ri && nums[ri]==trip[2]) --ri;
                }
            }
            while (i+1<n && nums[i]==nums[i+1]) ++i;
        }
        return res;
    }
};
