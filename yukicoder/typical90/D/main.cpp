#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

int main() {
    int n;
    cin >> n;
    vector<ll> e(n);
    rep(i, n) cin >> e[i];
    bool res = false;
    int m = 1;
    rep(i, n) m *= 3;
    rep(i, m) {
        vector<ll> sum(3);
        int ti = i;
        rep(j, n) {
            sum[ti%3] += e[j];
            ti /= 3;
        }
        bool ok = true;
        rep3(j, 1, 3) if (sum[j] != sum[0]) ok = false;
        if (ok) res = true;
    }
    if (res) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
