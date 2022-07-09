// 自力AC1

#include <bits/stdc++.h>
using namespace std;

class Solution {
    const int INF = (int)(1.5e9);
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size(), nlen = 1;
        while (nlen < n) nlen *= 2;
        vector<int> dat(nlen*2-1, -INF);
        auto update = [&](int k, int a) -> void {
            k += nlen-1;
            dat[k] = a;
            while (k > 0) {
                k = (k-1) / 2;
                dat[k] = max(dat[k*2+1], dat[k*2+2]);
            }
        };
        auto query = [&](auto query, int a, int b, int k=0, int l=0, int r=-1) -> int {
            if (r == -1) { r = nlen; k = 0; l = 0; }
            if (r<=a || b<=l) return -INF;
            if (a<=l && r<=b) return dat[k];
            else {
                int vl = query(query, a, b, k*2+1, l, (l+r)/2);
                int vr = query(query, a, b, k*2+2, (l+r)/2, r);
                return max(vl, vr);
            }
        };
        update(0, nums[0]);
        for (int i=1; i<n; ++i) {
            int mval = query(query, max(0, i-k), i);
            update(i, mval+nums[i]);
        }
        return query(query, n-1, n);
    }
};
