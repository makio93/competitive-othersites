#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 本番AC

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), m(n);
    vector<vector<int>> b(n);
    rep(i, n) {
        cin >> a[i] >> m[i];
        vector<int> bi(m[i]);
        rep(j, m[i]) cin >> bi[j];
        b[i] = bi;
    }
    vector<ll> dp(n+1);
    rep(i, n) {
        dp[i+1] = dp[i];
        rep(j, m[i]) dp[i+1] = max(dp[i+1], dp[b[i][j]]+max(0,a[i]-a[b[i][j]-1]));
    }
    cout << dp[n] << endl;
    return 0;
}
