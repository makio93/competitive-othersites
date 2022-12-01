#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

int main() {
    vector<int> a(3);
    rep(i, 3) cin >> a[i];
    ll k;
    cin >> k;
    vector<vector<vector<ll>>> dp(63, vector<vector<ll>>(100, vector<ll>(100)));
    rep(i, 100) {
        int ti = i, ni = 0, si = 0;
        rep(i2, 2) {
            si += ti % 10;
            ti /= 10;
        }
        si %= 10;
        ni = i * 10 % 100 + (si + a[0]) % 10;
        dp[0][i][ni%100]++;
    }
    rep(i, 62) rep(i1, 100) rep(j1, 100) {
        ll mval = 0;
        rep(i2, 100) mval += dp[i][i1][i2] * dp[i][i2][j1];
        dp[i+1][i1][j1] += mval;
    }
    k -= 3;
    bool fir = true;
    vector<vector<ll>> ans(100, vector<ll>(100));
    //ans[(a[1]*10+a[2])%100][(a[2]*10+(a[0]+a[1]+a[2])%10)%100]++;
    rep(i, 63) if ((k>>i)&1LL) {
        if (fir) {
            ans = dp[i];
            fir = false;
        }
        else {
            auto nans = ans;
            rep(i1, 100) rep(j1, 100) {
                ll mval = 0;
                rep(i2, 100) mval += dp[i][i1][i2] * ans[i2][j1];
                nans[i1][j1] += mval;
            }
            swap(ans, nans);
        }
    }
    vector<int> ori(100), tar(100);
    ori[(a[1]*10+a[2]%10)%100] = 1;
    rep(i, 100) rep(j, 100) tar[i] += ori[j] * ans[i][j];
    int res = 0;
    rep(i, 100) if (tar[i] > 0) {
        res = i % 10;
        break;
    }
    cout << res << endl;
    return 0;
}
