// 学習1回目,自力AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t0;
    cin >> t0;
    rep(i0, t0) {
        int n;
        cin >> n;
        vector<int> x(n), t(n);
        rep(i, n) cin >> x[i];
        rep(i, n) cin >> t[i];
        vector<pair<int, int>> xids(n);
        rep(i, n) xids[i] = { x[i], t[i] };
        sort(all(xids));
        rep(i, n) {
            x[i] = xids[i].first;
            t[i] = xids[i].second;
        }
        double li = 0.0, ri = (double)(x[n-1]);
        while (ri-li >= 1e-7) {
            double ci = (li+ri) / 2.0, lval = 0.0, rval = 0.0;
            rep(i, n) {
                if ((double)(x[i]) <= ci) lval = max(lval, ci-x[i]+t[i]);
                else rval = max(rval, x[i]-ci+t[i]);
            }
            if (lval >= rval) ri = ci;
            else li = ci;
        }
        cout << fixed << setprecision(10) << li << endl;
    }
    return 0;
}
