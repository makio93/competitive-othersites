// 自力AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int i=m-1; i>=0; --i) nums1[i+n] = nums1[i];
        int id = 0;
        for (int i=0; i<m; ++i) {
            while (id<n && nums2[id]<nums1[n+i]) {
                nums1[id+i] = nums2[id];
                ++id;
            }
            nums1[id+i] = nums1[n+i];
        }
        while (id < n) {
            nums1[id+m] = nums2[id];
            ++id;
        }
    }
};
