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
		int n;
		cin >> n;
		vector<int> a(n);
		rep(i, n) cin >> a[i];
		int two = 0;
		rep(i, n) while (a[i]%2 == 0) {
			a[i] /= 2;
			++two;
		}
		sort(all(a));
		ll mval = a[n-1];
		rep(i, two) mval *= 2;
		ll res = mval;
		rep(i, n-1) res += a[i];
		cout << res << endl;
	}
	return 0;
}
