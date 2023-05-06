// 学習1回目,解説AC1

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const double DINF = 1e9;

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
        double lv = 0.0, rv = DINF;
        while (rv-lv > 1e-7) {
            double cv = (lv+rv) / 2.0, lval = -DINF, rval = DINF;
            rep(i, n) if ((double)(t[i]) <= cv) {
                rval = min(rval, x[i]+(cv-t[i]));
                lval = max(lval, x[i]-(cv-t[i]));
            }
            if (rval >= lval) rv = cv;
            else lv = cv;
        }
        double lval = -DINF, rval = DINF;
        rep(i, n) {
                rval = min(rval, x[i]+(rv-t[i]));
                lval = max(lval, x[i]-(rv-t[i]));
        }
        cout << fixed << setprecision(10) << ((rval+lval)/2.0) << endl;
    }
    return 0;
}
