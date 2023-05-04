// 学習1回目,解説AC

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
        vector<pair<ll, ll>> llst, rlst;
        ll asum = 0, mval = 0;
        llst.emplace_back(asum, mval);
        repr(i, k) {
            asum += a[i];
            mval = min(mval, asum);
            if (i==0 || asum>=0) {
                llst.emplace_back(asum, mval);
                asum = 0, mval = 0;
            }
        }
        asum = 0, mval = 0;
        rlst.emplace_back(asum, mval);
        rep3(i, k+1, n) {
            asum += a[i];
            mval = min(mval, asum);
            if (i==n-1 || asum>=0) {
                rlst.emplace_back(asum, mval);
                asum = 0, mval = 0;
            }
        }
        int llen = llst.size(), rlen = rlst.size(), li = 0, ri = 0;
        ll sum = a[k];
        while (li+1<llen && ri+1<rlen) {
            if (llst[li+1].second+sum >= 0) {
                ++li;
                sum += llst[li].first;
            }
            else if (rlst[ri+1].second+sum >= 0) {
                ++ri;
                sum += rlst[ri].first;
            }
            else break;
        }
        if (li+1<llen && ri+1<rlen) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
    return 0;
}
