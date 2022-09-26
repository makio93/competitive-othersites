// 解説AC2

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
		int lval = INF, rval = -INF;
		rep(i, n) {
			lval = min(lval, x[i]-t[i]);
			rval = max(rval, x[i]+t[i]);
		}
		double res = (lval + rval) / 2.0;
		printf("%.10f\n", res);
	}
	return 0;
}
