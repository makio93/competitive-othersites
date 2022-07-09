// 本番TLE1

#include <bits/stdc++.h>
using namespace std;

struct SegmentTree {
    int n;
    vector<int> dat;
    SegmentTree() { init(1); }
    SegmentTree(int n_) { init(n_); }
    void init(int n_) {
        n = 1;
        while (n < n_) n *= 2;
        dat = vector<int>(2*n-1, (int)(1e9));
    }
    void update(int k, int a) {
        k += n-1;
        dat[k] = a;
        while (k > 0) {
            k = (k-1) / 2;
            dat[k] = min(dat[k*2+1], dat[k*2+2]);
        }
    }
    int query(int a, int b, int k=0, int l=0, int r=-1) {
        if (r == -1) { r = n; k = 0; l = 0; }
        if (r<=a || b<=l) return (int)(1e9);
        if (a<=l && r<=b) return dat[k];
        else {
            int vl = query(a, b, k*2+1, l, (l+r)/2);
            int vr = query(a, b, k*2+2, (l+r)/2, r);
            return min(vl, vr);
        }
    }
};
class Solution {
public:
    int validSubarraySize(vector<int>& nums, int threshold) {
        int n = nums.size();
        SegmentTree sg(n+1);
        for (int i=0; i<n; ++i) sg.update(i, nums[i]);
        for (int i=1; i<=n; ++i) if (i==1 || threshold/i!=threshold/(i-1)) {
            int tval = threshold / i;
            for (int j=0; j+i-1<n; ++j) if (sg.query(j, j+i) > tval) return i;
        }
        return -1;
    }
};
