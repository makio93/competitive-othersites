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
		int n, m, d;
		cin >> n >> m >> d;
		vector<int> p(n), a(m);
		rep(i, n) {
			cin >> p[i];
			p[i]--;
		}
		rep(i, m) {
			cin >> a[i];
			a[i]--;
		}
		vector<int> pids(n);
		rep(i, n) pids[p[i]] = i;
		int hval = -INF, lval = INF;
		rep(i, m-1) {
			hval = max(hval, pids[a[i+1]]-pids[a[i]]);
			lval = min(lval, pids[a[i+1]]-pids[a[i]]);
		}
		if (hval>d || lval<=0) {
			cout << 0 << endl;
			continue;
		}
		int res = lval;
		if (d+1 < n) res = min(res, (d+1)-hval);
		cout << res << endl;
	}
	return 0;
}
