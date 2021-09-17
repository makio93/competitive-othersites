#include <bits/stdc++.h>
using namespace std;

// 自力AC2

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> cnt;
        for (int ni : nums1) cnt[ni]++;
        vector<int> res;
        for (int ni : nums2) if (cnt.find(ni) != cnt.end()) {
            res.push_back(ni);
            cnt[ni]--;
            if (cnt[ni] <= 0) cnt.erase(ni);
        }
        return res;
    }
};
