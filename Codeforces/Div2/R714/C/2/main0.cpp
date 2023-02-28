// 学習2回目,自力AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const int INF = (int)(1e9), M = (int)(2e5);
const ll mod = (ll)(1e9) + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t0;
    cin >> t0;
    vector<ll> dp(M+10);
    rep(i, 10) dp[i] = 1;
    rep3(i, 10, M+10) dp[i] = (dp[i-9] + dp[i-10]) % mod;
    rep(i0, t0) {
        string n;
        int m;
        cin >> n >> m;
        ll res = 0;
        int nlen = n.length();
        rep(i, nlen) res = (res + dp[m+n[i]-'0']) % mod;
        cout << res << endl;
    }
    return 0;
}
