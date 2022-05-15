// 本番AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    int t0;
    cin >> t0;
    for (int i0=0; i0<t0; ++i0) {
        ll n, m, s;
        cin >> n >> m >> s;
        bool ok = true;
        if (s*2/n < n+1) ok = false;
        if (((s*2+n-1)/n+m-1)/m > n+1) ok = false;
        if (ok) cout << 1 << endl;
        else cout << 0 << endl;
    }
    return 0;
}
