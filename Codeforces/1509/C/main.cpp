#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

int main() {
	int n;
	cin >> n;
	vector<ll> a(n);
	rep(i, n) cin >> a[i];
	sort(all(a));
	vector<vector<ll>> dp(n, vector<ll>(n, (ll)(1e18)));
	dp[0][0] = a.back() - a.front();
	rep(i, n-1) {
		rep3(j, 0, i+1) {
			int l = j, r = (n-1) - (i-l);
			dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j]+(a[r]-a[l+1]));
			dp[i+1][j] = min(dp[i+1][j], dp[i][j]+(a[r-1]-a[l]));
		}
	}
	ll ans = (ll)(1e18);
	rep(i, n) ans = min(ans, dp[n-1][i]);
	cout << ans << endl;
	return 0;
}

