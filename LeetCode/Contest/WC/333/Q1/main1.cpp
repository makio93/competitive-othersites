// 解説AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int n = nums1.size(), m = nums2.size();
        map<int, int> mp;
        for (int i=0; i<n; ++i) mp[nums1[i][0]] += nums1[i][1];
        for (int i=0; i<m; ++i) mp[nums2[i][0]] += nums2[i][1];
        vector<vector<int>> res;
        for (const auto& pi : mp) res.push_back({ pi.first, pi.second });
        return res;
    }
};
