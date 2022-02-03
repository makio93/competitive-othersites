#include <bits/stdc++.h>
using namespace std;

// 自力AC

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int n = nums1.size(), res = 0;
        unordered_map<int, int> sum1, sum2;
        for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) sum1[nums1[i]+nums2[j]]++;
        for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) sum2[nums3[i]+nums4[j]]++;
        for (auto pi : sum1) if (sum2.find(-pi.first) != sum2.end()) res += pi.second * sum2[-pi.first];
        return res;
    }
};
