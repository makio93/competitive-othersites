// 学習1回目,解説AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

template <class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template <class T> bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const int INF = (int)(1e9);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, q;
    cin >> n >> m;
    vector<int> a(m);
    rep(i, m) cin >> a[i];
    int sl = 0;
    while (1<<sl <= m) ++sl;
    vector<vector<int>> st(sl, vector<int>(m));
    rep(i, m) st[0][i] = a[i];
    rep(i, sl-1) rep(j, m) {
        st[i+1][j] = st[i][j];
        if (j+(1<<i) < m) chmax(st[i+1][j], st[i][j+(1<<i)]);
    }
    vector<int> pw(m+1);
    rep3(i, 2, m+1) pw[i] = pw[i/2] + 1;
    auto query = [&](int li, int ri) -> int {
        return max(st[pw[ri-li]][li], st[pw[ri-li]][ri-(1<<pw[ri-li])]);
    };
    cin >> q;
    rep(i, q) {
        int xs, ys, xf, yf, k;
        cin >> xs >> ys >> xf >> yf >> k;
        --xs; --ys; --xf; --yf;
        if (abs(xs-xf)%k!=0 || abs(ys-yf)%k!=0) {
            cout << "NO" << endl;
            continue;
        }
        if (ys > yf) {
            swap(ys, yf);
            swap(xs, xf);
        }
        int mx = xs + (n - xs - 1) / k * k, mval = query(ys, yf+1);
        if (mx >= mval) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
