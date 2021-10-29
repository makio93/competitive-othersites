#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 本番AC

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t0;
	cin >> t0;
	rep(i0, t0) {
		ll n, k;
		cin >> n >> k;
		vector<int> a(n);
		rep(i, n) cin >> a[i];
		ll res = 0, kval = 0;
		bool fin = false;
		rep(i, n-1) {
			ll aval = 1;
			rep(j, a[i]) aval *= 10;
			ll mval = 1;
			rep(j, a[i+1]-a[i]) mval *= 10;
			--mval;
			if (kval+mval < k+1) {
				kval += mval;
				res += mval * aval;
			}
			else {
				res += ((k+1) - kval) * aval;
				kval = k+1;
				fin = true;
				break;
			}
		}
		if (!fin) {
			ll aval = 1;
			rep(j, a[n-1]) aval *= 10;
			res += ((k+1) - kval) * aval;
		}
		cout << res << endl;
	}
	return 0;
}
