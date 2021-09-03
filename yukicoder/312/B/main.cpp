#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 本番AC,嘘解法

int main() {
    ll n;
    cin >> n;
    ll res = n;
    for (ll r=2; r<=min((ll)(1.6e8),n); ++r) {
        ll rval = 1;
        int jcnt = 0;
        while (rval <= n/r) {
            rval *= r;
            ++jcnt;
        }
        res = min(res, r+jcnt+(n-rval));
    }
    ll r2 = (ll)(sqrt(n)), d2 = r2 * r2;
    res = min(res, r2+2+(n-d2));
    cout << res << endl;
    return 0;
}
