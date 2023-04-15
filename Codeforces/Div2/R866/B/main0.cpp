// 本番AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const int INF = (int)(1e9);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t0;
    cin >> t0;
    rep(i0, t0) {
        string s;
        cin >> s;
        int n = s.length(), bcnt = count(all(s), '1');
        if (bcnt == 0) {
            cout << 0 << endl;
            continue;
        }
        if (bcnt == n) {
            cout << ((ll)(n)*n) << endl;
            continue;
        }
        s += s;
        int mval = 0, lcnt = 0;
        rep(i, n*2) {
            if (s[i] == '1') ++lcnt;
            else {
                mval = max(mval, lcnt);
                lcnt = 0;
            }
        }
        ll res = (ll)((mval+1)/2) * ((mval+1)-(mval+1)/2);
        cout << res << endl;
    }
    return 0;
}
