#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 本番AC

ll gcd(ll a, ll b) { return (b ? gcd(b, a%b) : a); }

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t0;
	cin >> t0;
	rep(i0, t0) {
		int n;
		cin >> n;
		vector<int> a(n);
		rep(i, n) cin >> a[i];
		int mval = (int)(1e9);
		rep(i, n) mval = min(mval, a[i]);
		rep(i, n) a[i] -= mval;
		bool zero = true;
		rep(i, n) if (a[i] != 0) zero = false;
		if (zero) {
			cout << -1 << endl;
			continue;
		}
		sort(all(a));
		int sid = 0;
		while (a[sid] == 0) ++sid;
		ll res = a[sid];
		rep3(i, sid+1, n) res = gcd(res, a[i]);
		cout << res << endl;
	}
	return 0;
}
