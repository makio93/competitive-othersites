// 本番AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int n = nums1.size(), m = nums2.size(), id1 = 0, id2 = 0;
        vector<vector<int>> res;
        while (id1<n || id2<m) {
            if ((id1<n&&id2<m&&nums1[id1][0]<=nums2[id2][0]) || id2>=m) {
                if (res.empty() || nums1[id1][0]!=res.back()[0]) res.push_back(nums1[id1]);
                else res.back()[1] += nums1[id1][1];
                ++id1;
            }
            else {
                if (res.empty() || nums2[id2][0]!=res.back()[0]) res.push_back(nums2[id2]);
                else res.back()[1] += nums2[id2][1];
                ++id2;
            }
        }
        return res;
    }
};
