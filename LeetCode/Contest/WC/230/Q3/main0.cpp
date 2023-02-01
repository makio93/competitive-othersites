// 本番AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<int> vmap1(7), vmap2(7);
        int sum1 = 0, sum2 = 0;
        for (int i=0; i<n; ++i) {
            vmap1[nums1[i]]++;
            sum1 += nums1[i];
        }
        for (int i=0; i<m; ++i) {
            vmap2[nums2[i]]++;
            sum2 += nums2[i];
        }
        if (sum1 > sum2) {
            swap(sum1, sum2);
            swap(vmap1, vmap2);
        }
        vector<int> diff(6);
        for (int i=1; i<6; ++i) diff[6-i] += vmap1[i];
        for (int i=6; i>1; --i) diff[i-1] += vmap2[i];
        int sub = sum2 - sum1, cnt = 0;
        for (int i=5; i>=1; --i) {
            if (sub <= 0) break;
            cnt += min(diff[i], (sub+i-1)/i);
            sub -= diff[i] * i;
        }
        if (sub > 0) return -1;
        else return cnt;
    }
};
