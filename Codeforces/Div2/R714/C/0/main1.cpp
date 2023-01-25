// 

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const ll mod = (ll)(1e9) + 7;
const int M_MX = (int)(2e5);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t0;
    cin >> t0;
    vector<ll> dp(M_MX+11);
    rep(i, 10) dp[i] = 1;
    rep3(i, 10, M_MX+11) dp[i] = (dp[i-9] + dp[i-10]) % mod;
    rep(i0, t0) {
        int n, m;
        cin >> n >> m;
        ll res = 0;
        while (n) {
            res = (res + dp[n%10+m]) % mod;
            n /= 10;
        }
        cout << res << endl;
    }
    return 0;
}
