// 解説AC

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
        --k;
        vector<int> a(n);
        rep(i, n) cin >> a[i];
        if (k==0 || k==n-1) {
            cout << "YES" << endl;
            continue;
        }
        vector<pair<ll, ll>> llst, rlst;
        ll tsum = 0, tmval = LINF;
        repr(i, k) {
            tsum += a[i];
            tmval = min(tmval, tsum);
            if (i==0 || tsum>=0) {
                llst.emplace_back(tsum, tmval);
                tsum = 0, tmval = LINF;
            }
        }
        tsum = 0, tmval = LINF;
        rep3(i, k+1, n) {
            tsum += a[i];
            tmval = min(tmval, tsum);
            if (i==n-1 || tsum>=0) {
                rlst.emplace_back(tsum, tmval);
                tsum = 0, tmval = LINF;
            }
        }
        ll nval = a[k];
        int llen = llst.size(), rlen = rlst.size(), li = 0, ri = 0;
        bool ok = true;
        while (li<llen && ri<rlen) {
            if (nval < -max(llst[li].second, rlst[ri].second)) {
                ok = false;
                break;
            }
            if (nval >= -llst[li].second) {
                nval += llst[li].first;
                ++li;
            }
            if (nval >= -rlst[ri].second) {
                nval += rlst[ri].first;
                ++ri;
            }
        }
        if (ok) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
