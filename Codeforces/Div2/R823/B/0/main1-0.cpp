// 解説AC0

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
		vector<int> x(n), t(n);
		rep(i, n) cin >> x[i];
		rep(i, n) cin >> t[i];
		double lval = 0.0, rval = 1e9;
		while (abs(rval-lval) > 1e-6) {
			double cval = lval + (rval-lval) / 2.0, lid = -1e9, rid = 1e9;
			bool ok = true;
			rep(i, n) {
				double di = cval-t[i];
				if (di <= 0.0) {
					ok = false;
					break;
				}
				lid = max(lid, x[i]-di);
				rid = min(rid, x[i]+di);
			}
			if (ok && rid>lid) rval = cval;
			else lval = cval;
		}
		double lid = -1e9, rid = 1e9;
		rep(i, n) {
			double di = rval - t[i];
			lid = max(lid, x[i]-di);
			rid = min(rid, x[i]+di);
		}
		double res = lid + (rid-lid) / 2.0;
		printf("%.10f\n", res);
	}
	return 0;
}
