#include <bits/stdc++.h>
using namespace std;

// 解説AC,Time,Space共にO(n^2)

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int n = nums1.size(), res = 0;
        unordered_map<int, int> vcnt;
        for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) vcnt[nums1[i]+nums2[j]]++;
        for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) if (vcnt.find(-nums3[i]-nums4[j]) != vcnt.end()) res += vcnt[-nums3[i]-nums4[j]];
        return res;
    }
};
