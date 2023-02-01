// 本番AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

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
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        int n = chargeTimes.size();
        vector<ll> sums(n+1);
        for (int i=0; i<n; ++i) sums[i+1] += sums[i] + runningCosts[i];
        SegmentTree st(n+1);
        for (int i=0; i<n; ++i) st.update(i, chargeTimes[i]);
        int li = 0, ri = n+1;
        while (ri-li > 1) {
            int ci = li + (ri-li) / 2;
            bool ok = (ci == 0);
            if (ci > 0) {
                for (int i=0; i+ci-1<n; ++i) {
                    if ((sums[i+ci]-sums[i])*ci <= budget-st.query(i, i+ci)) ok = true;
                }
            }
            if (ok) li = ci;
            else ri = ci;
        }
        return li;
    }
};
