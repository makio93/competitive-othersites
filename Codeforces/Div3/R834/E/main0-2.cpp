// 本番AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

template <class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template <class T> bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const int INF = (int)(1e9);
const ll LINF = (ll)(1e18);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t0;
	cin >> t0;
	rep(i0, t0) {
		int n;
		ll h;
		cin >> n >> h;
		vector<int> a(n);
		rep(i, n) cin >> a[i];
		sort(all(a));
		vector<int> b = { 2, 2, 3 };
		vector<vector<ll>> dp(n+1, vector<ll>(1<<3, -LINF));
		dp[0][0] = h;
		int res = 0;
		rep(i, n) rep(j, 1<<3) {
			rep(j2, 1<<3) if ((j&j2) == j2) {
				int bm = 1;
				if (dp[i][j^j2] == -LINF) continue;
				rep(jj, 3) if (j2&(1<<jj)) bm *= b[jj];
				chmax(dp[i][j], dp[i][j^j2]*bm);
			}
			if (a[i] < dp[i][j]) {
				chmax(dp[i+1][j], dp[i][j]+a[i]/2);
				res = max(res, i+1);
			}
		}
		cout << res << endl;
	}
	return 0;
}
