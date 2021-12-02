#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 本番終了後,自力WA

int main() {
    int ti;
    cin >> ti;
    rep(i0, ti) {
        int k;
        cin >> k;
        string n;
        cin >> n;
        string res;
        if (k == 1) res = n;
        else if (n.find('1') != string::npos) res = "1";
        else {
            int k2 = min(k, 20);
            for (ll i=1; i<(1LL<<k2); ++i) {
                string t;
                rep(j, k2) if ((i>>j)&1) t += n[j];
                ll tval = stoll(t);
                bool prime = true;
                for (ll i2=2; i2*i2<=tval; ++i2) if (tval%i2 == 0LL) {
                    prime = false;
                    break;
                }
                if (!prime) {
                    res = t;
                    break;
                }
            }
            if (res.empty()) {
                int bi = k - k2;
                for (ll i=1; i<(1LL<<k2); ++i) {
                    string t;
                    rep(j, k2) if ((i>>j)&1) t += n[bi+j];
                    ll tval = stoll(t);
                    bool prime = true;
                    for (ll i2=2; i2*i2<=tval; ++i2) if (tval%i2 == 0LL) {
                        prime = false;
                        break;
                    }
                    if (!prime) {
                        res = t;
                        break;
                    }
                }
            }
        }
        cout << (int)(res.length()) << endl;
        cout << res << endl;
    }
    return 0;
}
