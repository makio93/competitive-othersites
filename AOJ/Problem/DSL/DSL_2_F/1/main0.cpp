// 復習1回目,自力AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const int IMAX = 0x7fffffff;

struct LazySegTree {
    int n;
    vector<int> dat, lazy;
    vector<bool> old;
    LazySegTree(int n_=0) {
        n = 1;
        while (n < n_) n *= 2;
        dat.resize(2*n-1, IMAX);
        lazy.resize(2*n-1, 0);
        old.resize(2*n-1, false);
    }
    void eval(int k, int l, int r) {
        if (old[k]) {
            dat[k] = lazy[k];
            if (r-l > 1) {
                lazy[2*k+1] = lazy[2*k+2] = lazy[k];
                old[2*k+1] = old[2*k+2] = old[k];
            }
            old[k] = false;
        }
    }
    void update(int a, int b, int x, int k=0, int l=0, int r=-1) {
        if (r == -1) r = n;
        eval(k, l, r);
        if (b<=l || r<=a) return;
        if (a<=l && r<=b) {
            lazy[k] = x;
            old[k] = true;
            eval(k, l, r);
        }
        else {
            update(a, b, x, k*2+1, l, l+(r-l)/2);
            update(a, b, x, k*2+2, l+(r-l)/2, r);
            dat[k] = min(dat[k*2+1], dat[k*2+2]);
        }
    }
    int find(int a, int b, int k=0, int l=0, int r=-1) {
        if (r == -1) r = n;
        eval(k, l, r);
        if (b<=l || r<=a) return IMAX;
        if (a<=l && r<=b) return dat[k];
        else {
            int vl = find(a, b, k*2+1, l, l+(r-l)/2);
            int vr = find(a, b, k*2+2, l+(r-l)/2, r);
            return min(vl, vr);
        }
    }
};

int main() {
    int n, q;
    cin >> n >> q;
    LazySegTree lst(n);
    rep(i, q) {
        int qi;
        cin >> qi;
        if (qi == 0) {
            int si, ti, xi;
            cin >> si >> ti >> xi;
            ++ti;
            lst.update(si, ti, xi);
        }
        else {
            int si, ti;
            cin >> si >> ti;
            ++ti;
            cout << lst.find(si, ti) << endl;
        }
    }
    return 0;
}
