#include <bits/stdc++.h>
using namespace std;

// 自力AC

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> cnt1, cnt2;
        for (int ni : nums1) cnt1[ni]++;
        for (int ni : nums2) cnt2[ni]++;
        vector<int> res;
        for (auto pi : cnt1) if (cnt2.find(pi.first) != cnt2.end()) for (int i=0; i<min(pi.second,cnt2[pi.first]); ++i) res.push_back(pi.first);
        return res;
    }
};
