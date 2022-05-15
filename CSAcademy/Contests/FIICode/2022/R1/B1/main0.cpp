// 本番AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll gcd(ll a, ll b) { return (b ? gcd(b, a%b) : a); }

const ll LINF = (ll)(2e18);

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i=0; i<n; ++i) cin >> a[i];
    sort(a.begin(), a.end());
    for (int i=1; i<n; ++i) a[i] -= a[0];
    int zid = -1;
    for (int i=1; i<n; ++i) if (a[i] != 0) {
        zid = i;
        break;
    }
    if (zid == -1) cout << -1 << endl;
    else {
        ll res = a[zid];
        for (int i=zid+1; i<n; ++i) res = gcd(res, a[i]);
        cout << res << endl;
    }
    return 0;
}
