// 復習1回目,自力AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

struct LazySegTree {
    int n;
    vector<ll> dat, lazy;
    LazySegTree(int n_=0) {
        n = 1;
        while (n < n_) n *= 2;
        dat.resize(2*n-1, 0);
        lazy.resize(2*n-1, 0);
    }
    void eval(int k, int l, int r) {
        if (lazy[k] != 0) {
            dat[k] += lazy[k];
            if (r-l > 1) {
                lazy[2*k+1] += lazy[k] / 2;
                lazy[2*k+2] += lazy[k] / 2;
            }
            lazy[k] = 0;
        }
    }
    void add(int a, int b, int x, int k=0, int l=0, int r=-1) {
        if (r == -1) r = n;
        eval(k, l, r);
        if (b<=l || r<=a) return;
        if (a<=l && r<=b) {
            lazy[k] += (ll)x * (r-l);
            eval(k, l, r);
        }
        else {
            add(a, b, x, k*2+1, l, l+(r-l)/2);
            add(a, b, x, k*2+2, l+(r-l)/2, r);
            dat[k] = dat[k*2+1] + dat[k*2+2];
        }
    }
    ll getSum(int a, int b, int k=0, int l=0, int r=-1) {
        if (r == -1) r = n;
        eval(k, l, r);
        if (b<=l || r<=a) return 0;
        if (a<=l && r<=b) return dat[k];
        else {
            ll vl = getSum(a, b, k*2+1, l, l+(r-l)/2);
            ll vr = getSum(a, b, k*2+2, l+(r-l)/2, r);
            return vl + vr;
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
            --si;
            lst.add(si, ti, xi);
        }
        else {
            int si, ti;
            cin >> si >> ti;
            --si;
            cout << lst.getSum(si, ti) << endl;
        }
    }
    return 0;
}
