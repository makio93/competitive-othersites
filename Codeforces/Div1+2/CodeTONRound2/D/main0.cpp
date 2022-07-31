// 本番AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const int INF = (int)(1e9);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t0;
	cin >> t0;
	rep(i0, t0) {
		int n, m;
		cin >> n >> m;
		vector<vector<ll>> c(n, vector<ll>(m));
		rep(i, n) rep(j, m) cin >> c[i][j];
		vector<ll> sums(n);
		rep(i, n) rep(j, m) sums[i] += c[i][j] * j;
		pair<ll, int> mval = { 0, -1 };
		rep(i, n) mval = max(mval, { sums[i], i });
		ll tval = (mval.second == 0) ? sums[1] : sums[0];
		cout << (mval.second+1) << ' ' << (mval.first-tval) << endl;
	}
	return 0;
}
