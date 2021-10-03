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
		int n, h;
		cin >> n >> h;
		vector<int> a(n);
		rep(i, n) cin >> a[i];
		sort(a.rbegin(), a.rend());
		int res = h / (a[0]+a[1]) * 2;
		h %= a[0] + a[1];
		if (h > 0) {
			++res;
			h -= a[0];
			if (h > 0) ++res;
		}
		cout << res << endl;
	}
	return 0;
}
