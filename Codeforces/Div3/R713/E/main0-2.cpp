// 終了後,自力AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t0;
    cin >> t0;
    rep(i0, t0) {
        int n, l, r, s;
        cin >> n >> l >> r >> s;
        --l;
        int len = r - l, lval = 1, nval = len * (len+1) / 2;
        if (s < nval) {
            cout << -1 << endl;
            continue;
        }
        if (nval < s) {
            rep3(i, 2, n-len+2) {
                nval += len;
                lval = i;
                if (nval >= s) break;
            }
        }
        if (nval < s) {
            cout << -1 << endl;
            continue;
        }
        vector<int> res(n);
        rep(i, len) res[l+i] = lval + i;
        int sub = nval - s;
        rep(i, sub) res[l+i]--;
        set<int> svals;
        rep3(i, 1, n+1) svals.insert(i);
        rep3(i, l, r) svals.erase(res[i]);
        rep(i, n) if (res[i] == 0) {
            res[i] = *svals.begin();
            svals.erase(svals.begin());
        }
        rep(i, n) cout << res[i] << (i<n-1?' ':'\n');
    }
    return 0;
}
