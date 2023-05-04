// 学習1回目,自力WA

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const ll LINF = (ll)(1e18);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t0;
    cin >> t0;
    rep(i0, t0) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        rep(i, n) cin >> a[i];
        vector<ll> lsum(n+2), rsum(n+2);
        rep(i, n+1) lsum[i+1] += lsum[i] + (i < n ? a[i] : 0);
        repr(i, n+1) rsum[i] += rsum[i+1] + (i-1 >= 0 ? a[i-1] : 0);
        ll lval = LINF, rval = LINF;
        rep3(i, 1, k+1) lval = min(lval, rsum[i]-rsum[k+1]);
        rep3(i, k, n+1) rval = min(rval, lsum[i]-lsum[k-1]);
        if (lval>=0 || rval>=0) {
            cout << "YES" << endl;
            continue;
        }
        ll aval = 0, bval = 0;
        rep3(i, k+1, n+1) {
            if (lsum[i]-lsum[k-1] < 0) break;
            aval = max(aval, lsum[i]-lsum[k]);
        }
        rep3r(i, 1, k) {
            if (rsum[i]-rsum[k+1] < 0) break;
            bval = max(bval, rsum[i]-rsum[k]);
        }
        if (lval+aval>=0 || rval+bval>=0) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
