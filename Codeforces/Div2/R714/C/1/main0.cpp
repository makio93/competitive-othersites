// 自力AC,学習1回目

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const ll mod = (ll)(1e9) + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t0;
    cin >> t0;
    vector<int> n(t0), m(t0);
    rep(i, t0) cin >> n[i] >> m[i];
    int mval = *max_element(all(m));
    vector<ll> dp(mval+11);
    rep(i, 10) dp[i] = 1;
    rep3(i, 10, mval+11) dp[i] = (dp[i] + dp[i-9] + dp[i-10]) % mod;
    rep(i0, t0) {
        ll res = 0;
        while (n[i0] > 0) {
            res = (res + dp[m[i0]+n[i0]%10]) % mod;
            n[i0] /= 10;
        }
        cout << res << endl;
    }
    return 0;
}
