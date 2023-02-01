// 本番AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        vector<int> slst;
        for (int i=0; i<n; ++i) if (nums1[i] != nums2[i]) slst.push_back(abs(nums1[i]-nums2[i]));
        ll sum = 0;
        for (int val : slst) sum += val;
        if (sum <= (ll)k1+k2) return 0;
        int mval = 0;
        for (int val : slst) mval = max(mval, val);
        int li = 0, ri = mval;
        while (ri-li > 1) {
            int ci = ri - (ri-li) / 2;
            ll scnt = 0;
            for (int val : slst) scnt += max(0, val-ci);
            if (scnt <= (ll)k1+k2) ri = ci;
            else li = ci;
        }
        int rcnt = k1 + k2;
        for (int& val : slst) if (val > ri) {
            rcnt -= val - ri;
            val = ri;
        }
        sort(slst.begin(), slst.end());
        for (int& val : slst) {
            if (rcnt == 0) break;
            if (val >= ri) {
                --val;
                --rcnt;
            }
        }
        ll res = 0;
        for (int& val : slst) res += (ll)val * val;
        return res;
    }
};
