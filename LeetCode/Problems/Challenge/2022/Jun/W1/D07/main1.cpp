// 解説AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int id1 = m-1, id2 = n-1;
        for (int i=m+n-1; i>=0; --i) {
            if (id2<0 || (id1>=0 && nums2[id2]<nums1[id1])) {
                nums1[i] = nums1[id1];
                --id1;
            }
            else {
                nums1[i] = nums2[id2];
                --id2;
            }
        }
    }
};
