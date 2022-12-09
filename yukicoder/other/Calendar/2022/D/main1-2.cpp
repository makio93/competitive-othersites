// 解説AC2

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const ll mod = (ll)(1e9) + 7;

int main() {
    int n;
    string s;
    cin >> n >> s;
    vector<vector<ll>> dp(n, vector<ll>(3));
    rep(i, 3) dp[0][i] = (s[0]-'A' == i) ? 0 : 1;
    ll two = 1;
    rep3(i, 1, n) {
        two = two * 2 % mod;
        rep(j, 3) {
            if (s[i]-'A' == j) dp[i][j] = dp[i-1][j];
            else {
                int ti = -1;
                rep(j2, 3) if (j2!=s[i]-'A' && j2!=j) ti = j2;
                dp[i][j] = (dp[i-1][ti] + two) % mod;
            }
        }
    }
    cout << dp[n-1][0] << endl;
    return 0;
}
