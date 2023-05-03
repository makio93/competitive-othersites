// 解説AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        auto diff_vector = [](vector<int>& vec1, vector<int>& vec2) -> vector<int> {
            unordered_set<int> fst, tst(vec2.begin(), vec2.end());
            for (const int& vi : vec1) if (tst.find(vi) == tst.end()) fst.insert(vi);
            return vector<int>(fst.begin(), fst.end());
        };
        return vector<vector<int>>({ diff_vector(nums1, nums2), diff_vector(nums2, nums1) });
    }
};
