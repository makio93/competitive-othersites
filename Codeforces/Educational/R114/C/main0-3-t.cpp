#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const ll INF = (2e18);

int main() {
	int n, m;
	cin >> n;
	vector<ll> a(n);
	rep(i, n) cin >> a[i];
	ll sum = 0;
	rep(i, n) sum += a[i];
	a.push_back(INF);
	sort(all(a));
	cin >> m;
	vector<ll> x(m), y(m);
	rep(i, m) cin >> x[i] >> y[i];
	rep(i, m) {
		ll res = 0;
		auto itr = lower_bound(all(a), x[i]);
		if (*itr == INF) res = (x[i]-a[n-1]) + max(0LL, y[i]-(sum-a[n-1]));
		else if (sum-(*itr) < y[i]) {
			res = max(0LL, y[i]-(sum-(*itr)));
			if (itr != a.begin()) {
				auto pitr = prev(itr);
				res = min(res, (x[i]-(*pitr))+max(0LL,y[i]-(sum-(*pitr))));
			}
		}
		cout << res << endl;
	}
	return 0;
}
