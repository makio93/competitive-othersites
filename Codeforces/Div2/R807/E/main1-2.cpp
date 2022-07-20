// 解説AC2

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

template<typename T>
class LazySegmentTree {
    int n;
    vector<T> node, lazy;
public:
    LazySegmentTree(int n_) : LazySegmentTree(vector<T>(n_)) {}
    LazySegmentTree(vector<T> v) {
        int n_ = v.size();
        n = 1;
        while (n < n_) n *= 2;
        node.resize(n*2-1, 0);
        lazy.resize(n*2-1, 0);
        for (int i=0; i<n_; ++i) node[n+i-1] = v[i];
        for (int i=n-2; i>=0; --i) node[i] = node[i*2+1] + node[i*2+2];
    }
    void eval(int k, int l, int r) {
        if (lazy[k] != 0) {
            node[k] += lazy[k];
            if (r-l > 1) {
                lazy[k*2+1] += lazy[k] / 2;
                lazy[k*2+2] += lazy[k] / 2;
            }
            lazy[k] = 0;
        }
    }
    void add(int a, int b, T x, int k=0, int l=0, int r=-1) {
        if (r == -1) r = n;
        eval(k, l, r);
        if (b<=l || r<=a) return;
        if (a<=l && r<=b) {
            lazy[k] += x * (r-l);
            eval(k, l, r);
        }
        else {
            add(a, b, x, k*2+1, l, (l+r)/2);
            add(a, b, x, k*2+2, (l+r)/2, r);
            node[k] = node[k*2+1] + node[k*2+2];
        }
    }
    T getSum(int a, int b, int k=0, int l=0, int r=-1) {
        if (r == -1) r = n;
        eval(k, l, r);
        if (b<=l || r<=a) return 0;
        if (a<=l && r<=b) return node[k];
        T vl = getSum(a, b, k*2+1, l, (l+r)/2);
        T vr = getSum(a, b, k*2+2, (l+r)/2, r);
        return vl + vr;
    }
    int getRightId(int a, int pre, int tar, int k=0, int l=0, int r=-1) {
        if (r == -1) r = n;
        eval(k, l, r);
        if (r-l == 1) {
            if (node[k] == tar) return l;
            else return l-1;
        }
        int mid = (l+r) / 2;
        eval(k*2+1, l, mid);
        if (a >= mid) return getRightId(a, pre-node[k*2+1], tar, k*2+2, mid, r);
        else if (node[k*2+1]-pre == tar*(mid-a)) return getRightId(mid, 0, tar, k*2+2, mid, r);
        else return getRightId(a, pre, tar, k*2+1, l, mid);
    }
    int getMaxId(int k=0, int l=0, int r=-1) {
        if (r == -1) r = n;
        eval(k, l, r);
        if (r-l == 1) {
            if (node[k] == 1) return l;
            else return l-1;
        }
        int mid = (l+r) / 2;
        eval(k*2+2, mid, r);
        if (node[k*2+2] == 0) return getMaxId(k*2+1, l, mid);
        else return getMaxId(k*2+2, mid, r);
    }
    void addBit(int val) {
        int rid = getRightId(val, getSum(0, val), 1) + 1;
        add(val, rid, -1);
        add(rid, rid+1, 1);
    }
    void remBit(int val) {
        int rid = getRightId(val, getSum(0, val), 0) + 1;
        add(val, rid, 1);
        add(rid, rid+1, -1);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<int> a(n), ki(q), li(q);
    int mval = 0;
    rep(i, n) {
        cin >> a[i];
        mval = max(mval, a[i]);
    }
    rep(i, q) {
        cin >> ki[i] >> li[i];
        ki[i]--;
        mval = max(mval, li[i]);
    }
    LazySegmentTree<int> lst(mval+5);
    rep(i, n) lst.addBit(a[i]);
    rep(i, q) {
        lst.remBit(a[ki[i]]);
        a[ki[i]] = li[i];
        lst.addBit(li[i]);
        cout << lst.getMaxId() << endl;
    }
    return 0;
}
