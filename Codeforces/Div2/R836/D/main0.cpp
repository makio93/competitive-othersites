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
		int n;
		cin >> n;
		ll sval = 1 + (ll)(4 + n+2) * (n-1) / 2, tval = (ll)(n+1) * (n+1);
		int nval = 1;
		while (sval < tval) {
			sval += n;
			++nval;
		}
		vector<ll> res(n);
		res[0] = nval;
		iota(res.begin()+1, res.end(), nval+3);
		ll sub = sval - tval;
		rep3(i, 1, n-1) {
			if (sub == 0) break;
			res[i]--;
			--sub;
		}
		if (sub > 0) {
			rep3(i, 1, n-1) {
				if (sub == 0) break;
				res[i]--;
				--sub;
			}
		}
		rep(i, n) cout << res[i] << (i<n-1?' ':'\n');
	}
	return 0;
}
