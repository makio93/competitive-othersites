#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 本番後,自力TLE2

int main() {
	int n, m;
	cin >> n;
	vector<ll> a(n);
	rep(i, n) cin >> a[i];
	ll sum = 0;
	rep(i, n) sum += a[i];
	sort(all(a));
	vector<pair<ll, int>> alst(n);
	rep(i, n) alst[i] = { a[i], i };
	cin >> m;
	vector<ll> x(m), y(m);
	rep(i, m) cin >> x[i] >> y[i];
	rep(i, m) {
		ll res = 0;
		auto itr = lower_bound(all(alst), pair(x[i], 0));
		if (itr == alst.end()) res = (x[i]-a[n-1]) + max(0LL, y[i]-(sum-a[n-1]));
		else if (sum-a[itr->second] < y[i]) {
			res = max(0LL, y[i]-(sum-a[itr->second]));
			if (itr != alst.begin()) res = min(res, (x[i]-a[itr->second-1])+max(0LL,y[i]-(sum-a[itr->second-1])));
		}
		cout << res << endl;
	}
	return 0;
}
