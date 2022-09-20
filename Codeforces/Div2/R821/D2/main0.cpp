// 自力AC

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
		int n, x, y;
		string a, b;
		cin >> n >> x >> y >> a >> b;
		vector<int> ids;
		rep(i, n) if (a[i] != b[i]) ids.push_back(i);
		int m = ids.size();
		if (m%2 == 1) {
			cout << -1 << endl;
			continue;
		}
		if (m == 0) {
			cout << 0 << endl;
			continue;
		}
		ll res = LINF;
		if (x >= y) {
			if (m==2 && ids[0]+1==ids[1]) res = min((ll)y*2, (ll)x);
			else res = m / 2 * (ll)y;
		}
		else {
			int sval = y / x, k = m / 2;
			vector<vector<ll>> dp(m+1, vector<ll>(k+1, LINF));
			dp[0][0] = dp[1][0] = 0;
			rep3(i, 2, m+1) {
				bool close = (ids[i-1] - ids[i-2] <= sval);
				ll xval = (ll)(ids[i-1] - ids[i-2]) * x;
				rep(j, k+1) {
					if (dp[i-1][j] != LINF) dp[i][j] = min(dp[i][j], dp[i-1][j]);
					if (close && j-1>=0 && dp[i-2][j-1]!=LINF) dp[i][j] = min(dp[i][j], dp[i-2][j-1]+xval);
				}
			}
			rep(i, k+1) res = min(res, dp[m][i]+(ll)(k-i)*y);
		}
		cout << res << endl;
	}
	return 0;
}
