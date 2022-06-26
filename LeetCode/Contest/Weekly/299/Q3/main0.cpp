// 本番AC

#include <bits/stdc++.h>
using namespace std;

const int INF = (int)(1e9);
class Solution {
public:
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), sum1 = 0, sum2 = 0;
        for (int i=0; i<n; ++i) sum1 += nums1[i];
        for (int i=0; i<n; ++i) sum2 += nums2[i];
        if (sum1 < sum2) {
            swap(nums1, nums2);
            swap(sum1, sum2);
        }
        int tsum1 = 0, tsum2 = 0;
        vector<int> subs(n+1);
        for (int i=0; i<n; ++i) {
            tsum1 += nums1[i];
            tsum2 += nums2[i];
            subs[i+1] = tsum1 - tsum2;
        }
        int mx = 0, mn = 0, lval = 0, rval = 0;
        for (int i=0; i<n; ++i) {
            lval = min(lval, subs[i+1]-mx);
            rval = max(rval, subs[i+1]-mn);
            mn = min(mn, subs[i+1]);
            mx = max(mx, subs[i+1]);
        }
        return max(sum1-lval, sum2+rval);
    }
};
