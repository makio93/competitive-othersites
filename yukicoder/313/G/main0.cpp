#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 本番後,自力WA

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

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), m(n);
    vector<vector<int>> b(n);
    rep(i, n) {
        cin >> a[i] >> m[i];
        vector<int> bi(m[i]);
        rep(j, m[i]) {
            cin >> bi[j];
            bi[j]--;
        }
        b[i] = bi;
    }
    vector<pair<int, pair<int, int>>> vals;
    rep(i, n) rep(j, m[i]) if (a[i]-a[b[i][j]] > 0) vals.emplace_back(-i, make_pair(a[i]-a[b[i][j]], j));
    sort(vals.rbegin(), vals.rend());
    SegmentTree st(n+2);
    ll res = 0;
    for (auto p : vals) {
        int ri = -p.first+1, li = p.second.second+1;
        if (st.query(li, ri) < k) {
            res += p.second.first;
            rep3(i, li, ri) {
                int pval = st.query(i, i+1);
                st.update(i, pval+1);
            }
        }
    }
    cout << res << endl;
    return 0;
}
