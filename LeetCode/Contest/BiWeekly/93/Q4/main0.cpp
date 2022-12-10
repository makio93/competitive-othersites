// 本番AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
class Solution {
public:
    ll minimumTotalCost(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        ll res = 0;
        vector<bool> same(n);
        unordered_map<int, int> scnt;
        int ssum = 0, li = -1;
        pair<int, int> mval = { 0, -1 };
        for (int i=0; i<n; ++i) if (nums1[i] == nums2[i]) {
            same[i] = true;
            scnt[nums1[i]]++;
            mval = max(mval, { scnt[nums1[i]], nums1[i] });
            ++ssum;
            res += i;
            if (li == -1) li = i;
        }
        if (mval.first*2 > ssum) {
            int tval = mval.second, sub = ssum - (ssum-mval.first) * 2;
            bool ok = false;
            for (int i=0; i<n; ++i) if (!same[i] && nums1[i]!=tval && nums2[i]!=tval) {
                --sub;
                res += i;
                if (sub == 0) {
                    ok = true;
                    break;
                }
            }
            if (!ok) return -1;
        }
        else if (ssum%2 == 1) res += li;
        return res;
    }
};
