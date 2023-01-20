// 本番AC

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

const int INF = (int)(1e9);

int main() {
	int n;
	cin >> n;
	vector<int> a(n*2), b(n*2), x(n), y(n);
	rep(i, n*2) cin >> a[i];
	rep(i, n*2) cin >> b[i];
	rep(i, n) cin >> x[i];
	rep(i, n) cin >> y[i];
	vector<vector<ll>> dp(n*2+1, vector<ll>(2));
	rep(i, 2*n) {
		if (i%2 == 0) {
			dp[i+1][0] = max(dp[i][0]+a[i], dp[i][1]+a[i]);
			dp[i+1][1] = max(dp[i][0]+b[i], dp[i][1]+b[i]);
		}
		else {
			dp[i+1][0] = max(dp[i][0]+a[i]+x[i/2], dp[i][1]+a[i]+y[i/2]);
			dp[i+1][1] = max(dp[i][0]+b[i]+y[i/2], dp[i][1]+b[i]+x[i/2]);
		}
	}
	ll res = max(dp[n*2][0], dp[n*2][1]);
	cout << res << endl;
	return 0;
}
