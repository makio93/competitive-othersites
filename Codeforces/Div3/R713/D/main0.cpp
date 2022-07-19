// 本番AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
#define v(t) vector<t>
#define p(t) pair<t, t>
#define p2(t, s) pair<t, s>
#define vp(t) v(p(t))

#define rep(i, n) for (int i=0,i##_len=((int)(n)); i<i##_len; ++i)
#define rep2(i, a, n) for (int i=((int)(a)),i##_len=((int)(n)); i<=i##_len; ++i)
#define repr(i, n) for (int i=((int)(n)-1); i>=0; --i)
#define rep2r(i, a, n) for (int i=((int)(n)),i##_len=((int)(a)); i>=i##_len; --i)

#define repi(itr, c) for (__typeof((c).begin()) itr=(c).begin(); itr!=(c).end(); ++itr)
#define repir(itr, c) for (__typeof((c).rbegin()) itr=(c).rbegin(); itr!=(c).rend(); ++itr)

#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define RSORT(x) sort(rall(x));
#define pb push_back
#define eb emplace_back

#define INF (1e9)
#define LINF (1e18)
#define PI (acos(-1))
#define EPS (1e-7)
#define DEPS (1e-10)

int main(){
    int t;
    cin >> t;
    rep(i1, t) {
        int n;
        cin >> n;
        v(int) b(n+2);
        rep(i, n+2) cin >> b[i];
        VSORT(b);
        ll sum = 0;
        rep(i, n+1) sum += b[i];
        bool ok = false;
        int pos = -1;
        v(int) a;
        rep(i, n+1) {
            if (b.back() == sum-b[i]) {
                ok = true;
                pos = i;
                break;
            }
        }
        if (ok) {
            rep(i, n+1) if (i != pos) a.pb(b[i]);
        }
        if (!ok) {
            if (sum-b[n] == (ll)b[n]) {
                ok = true;
                rep(i, n) a.pb(b[i]);
            }
        }
        if (ok) {
            rep(i, n) printf("%d%c", a[i], (i<n-1?' ':'\n'));
        }
        else cout << -1 << endl;
    }
    return 0;
}
