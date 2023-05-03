// 自力AC2

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        unordered_set<int> st1(nums1.begin(), nums1.end()), st2(nums2.begin(), nums2.end());
        vector<vector<int>> res(2);
        for (const int& si : st1) if (st2.find(si) == st2.end()) res[0].push_back(si);
        for (const int& si : st2) if (st1.find(si) == st1.end()) res[1].push_back(si);
        return res;
    }
};
