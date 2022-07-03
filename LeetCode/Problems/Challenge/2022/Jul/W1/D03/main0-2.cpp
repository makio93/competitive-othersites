// 自力AC2

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
        dat = vector<int>(2*n-1, 0);
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
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        SegmentTree std(1001), stu(1001);
        int res = 0;
        for (int i=0; i<n; ++i) {
            int uval = std.query(0, nums[i]) + 1;
            int dval = stu.query(nums[i]+1, 1001) + 1;
            res = max({ res, uval, dval });
            std.update(nums[i], max(std.query(nums[i], nums[i]+1), dval));
            stu.update(nums[i], max(stu.query(nums[i], nums[i]+1), uval));
        }
        return res;
    }
};
