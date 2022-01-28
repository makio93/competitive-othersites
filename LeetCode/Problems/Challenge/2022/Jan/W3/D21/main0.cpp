#include <bits/stdc++.h>
using namespace std;

// 自力AC

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
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        vector<int> sub(n*2+1);
        for (int i=0; i<2*n; ++i) sub[i+1] = sub[i] + gas[i%n] - cost[i%n];
        SegmentTree sg(n*2);
        for (int i=0; i<2*n; ++i) sg.update(i, sub[i+1]);
        for (int i=0; i<n; ++i) if (sg.query(i, i+n) >= sub[i]) return i;
        return -1;
    }
};
