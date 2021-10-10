#include <bits/stdc++.h>
using namespace std;

// 本番AC

class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        unordered_map<int, int> cnt;
        for (vector<int> nums : vector<vector<int>>({ nums1, nums2, nums3 })) {
            sort(nums.begin(), nums.end());
            nums.erase(unique(nums.begin(), nums.end()), nums.end());
            for (int nval : nums) cnt[nval]++;
        }
        vector<int> res;
        for (auto p : cnt) if (p.second >= 2) res.push_back(p.first);
        return res;
    }
};
