#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

int main() {
    ll n;
    cin >> n;
    ll n2 = n * n;
    ll res = 0;
    for (ll x=1; x*x*2<=n2; ++x) {
        ll y2 = n2 - x*x;
        ll y1 = (ll)round(sqrt(y2)) - 1;
        while (y1*y1 < y2) ++y1;
        if (y1*y1 == y2) {
            if (y1 == x) ++res;
            else res += 2;
        }
    }
    cout << res << endl;
    return 0;
}
