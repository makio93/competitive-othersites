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
		vector<vector<int>> c(n, vector<int>(m));
		rep(i, n) rep(j, m) cin >> c[i][j];
		vector<int> cvals;
		vector<ll> csums;
		ll res = 0;
		rep(i, m) {
			cvals.assign(n, 0LL);
			rep(j, n) cvals[j] = c[j][i];
			sort(all(cvals));
			csums.assign(n+1, 0LL);
			rep(j, n) csums[j+1] = csums[j] + cvals[j];
			rep(j, n-1) res += (csums[n] - csums[j+1]) - (ll)cvals[j] * (n-j-1);
		}
		cout << res << endl;
	}
	return 0;
}
