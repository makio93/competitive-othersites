// 本番TLE2

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

vector<vector<int>> dat((int)(3e3), vector<int>((int)(3e3)));
struct SegmentTree {
    int n, m;
    SegmentTree() { init(1, 1); }
    SegmentTree(int n_, int m_) { init(n_, m_); }
    void init(int n_, int m_) {
        n = 1, m = 1;
        while (n < n_) n *= 2;
        while (m < m_) m *= 2;
        rep(i, 2*n-1) rep(j, 2*m-1) dat[i][j] = (int)(1e9);
    }
    void update(int k1, int k2, int a) {
        k1 += n-1;
        k2 += m-1;
        {
            int tk = k2;
            dat[k1][tk] = a;
            while (tk > 0) {
                tk = (tk-1) / 2;
                dat[k1][tk] = min(dat[k1][tk*2+1], dat[k1][tk*2+2]);
            } 
        }
        while (k1 > 0) {
            k1 = (k1-1) / 2;
            int tk = k2;
            dat[k1][tk] = min(dat[k1*2+1][tk], dat[k1*2+2][tk]);
            while (tk > 0) {
                tk = (tk-1) / 2;
                dat[k1][tk] = min(dat[k1][tk*2+1], dat[k1][tk*2+2]);
            }
        }
    }
    int query(int a1, int b1, int a2, int b2, int k1=0, int k2=0, int l1=0, int r1=-1, int l2=0, int r2=-1) {
        if (r1 == -1) { r1 = n; k1 = 0; l1 = 0; }
        if (r2 == -1) { r2 = m; k2 = 0; l2 = 0; }
        if (r1<=a1||b1<=l1||r2<=a2||b2<=l2) return (int)(1e9);
        if (a1<=l1&&r1<=b1&&a2<=l2&&r2<=b2) return dat[k1][k2];
        else if (a1<=l1 && r1<=b1) {
            int vl2 = query(a1, b1, a2, b2, k1, k2*2+1, l1, r1, l2, (l2+r2)/2);
            int vr2 = query(a1, b1, a2, b2, k1, k2*2+2, l1, r1, (l2+r2)/2, r2);
            return min(vl2, vr2);
        }
        else {
            int vl = query(a1, b1, a2, b2, k1*2+1, k2, l1, (l1+r1)/2, l2, r2);
            int vr = query(a1, b1, a2, b2, k1*2+2, k2, (l1+r1)/2, r1, l2, r2);
            return min(vl, vr);
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t0;
    cin >> t0;
    vector<vector<int>> a;
    SegmentTree st(1, 1);
    rep(i0, t0) {
        int n, m;
        cin >> n >> m;
        bool rev = (n > m);
        if (!rev) {
            a.assign(n, vector<int>(m));
            rep(i, n) rep(j, m) cin >> a[i][j];
        }
        else {
            a.assign(m, vector<int>(n));
            rep(i, n) rep(j, m) cin >> a[j][i];
            swap(n, m);
        }
        st.init(n, m);
        rep(i, n) rep(j, m) st.update(i, j, a[i][j]);
        int res = 0;
        rep(i, n) rep(j, m) if (res < min(i,j)+1) {
            int li = 1, ri = min(i, j) + 2;
            while (ri-li > 1) {
                int ci = li + (ri-li) / 2;
                int tui = max(0, i-ci+1), tli = max(0, j-ci+1);
                int val = st.query(tui, i+1, tli, j+1);
                if (val >= ci) li = ci;
                else ri = ci;
            }
            res = max(res, li);
        }
        cout << res << endl;
    }
    return 0;
}
