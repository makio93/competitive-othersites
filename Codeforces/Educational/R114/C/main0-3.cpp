#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 本番後,自力TLE(WA)

int main() {
	int n, m;
	cin >> n;
	vector<ll> a(n);
	rep(i, n) cin >> a[i];
	ll sum = 0;
	rep(i, n) sum += a[i];
	sort(all(a));
	cin >> m;
	vector<ll> x(m), y(m);
	rep(i, m) cin >> x[i] >> y[i];
	rep(i, m) {
		ll res = 0;
		int li = 0, ri = n;
		while (ri-li > 1) {
			int ci = (li + ri) / 2;
			if (a[ci] < x[i]) li = ci;
			else ri = ci;
		}
		if (ri == n) res = (x[i]-a.back()) + max(0LL, y[i]-(sum-a.back()));
		else if (sum-a[ri] < y[i]) {
			res = y[i] - (sum-a[ri]);
			if (ri-1 >= 0) res = min(res, (x[i]-a[ri-1])+max(0LL,y[i]-(sum-a[ri-1])));
		}
		cout << res << endl;
	}
	return 0;
}
