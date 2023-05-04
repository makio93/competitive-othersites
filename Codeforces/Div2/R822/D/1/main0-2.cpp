// 学習1回目,自力AC

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
        auto check = [&n](vector<int>& b, int si) -> bool {
            pair<ll, ll> mval = { 0, 0 };
            vector<pair<ll, ll>> rlst;
            rlst.emplace_back(0, 0);
            ll rsum = 0, lsum = 0;
            rep3(i, si+1, n) {
                rsum += b[i];
                if (mval.second < rsum) rlst.emplace_back(mval.first, rsum);
                mval = { min(mval.first, rsum), max(mval.second, rsum) };
            }
            int ri = 0, m = rlst.size();
            repr(i, si+1) {
                lsum += b[i];
                if (lsum+rlst[ri].second < 0) return false;
                while (ri+1<m && lsum+rlst[ri+1].first>=0) ++ri;
            }
            return true;
        };
        if (check(a, k)) cout << "YES" << endl;
        else {
            reverse(all(a));
            if (check(a, (n-1)-k)) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
    return 0;
}
