// 本番AC

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
        dat = vector<int>(2*n-1);
    }
    void update(int k, int a) {
        k += n-1;
        dat[k] = a;
        while (k > 0) {
            k = (k-1) / 2;
            dat[k] = max(dat[k*2+1], dat[k*2+2]);
        }
    }
    int query(int a, int b, int k=0, int l=0, int r=-1) {
        if (r == -1) { r = n; k = 0; l = 0; }
        if (r<=a || b<=l) return 0;
        if (a<=l && r<=b) return dat[k];
        else {
            int vl = query(a, b, k*2+1, l, (l+r)/2);
            int vr = query(a, b, k*2+2, (l+r)/2, r);
            return max(vl, vr);
        }
    }
};

class Solution {
    const int MAX = (int)(1e5);
public:
    int lengthOfLIS(vector<int>& nums, int k) {
        int n = nums.size();
        SegmentTree st(MAX+1);
        for (int i=0; i<n; ++i) {
            int li = max(0, nums[i]-k), tval = st.query(li, nums[i]);
            st.update(nums[i], max(st.query(nums[i], nums[i]+1), tval+1));
        }
        return st.query(0, MAX+1);
    }
};
