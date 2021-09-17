#include <bits/stdc++.h>
using namespace std;

// 解説AC2

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> cnt;
        for (int ni : nums1) cnt[ni]++;
        vector<int> res;
        for (int ni : nums2) {
            if (cnt[ni] > 0) res.push_back(ni);
            cnt[ni]--;
        }
        return res;
    }
};
