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
		int n, x;
		cin >> n >> x;
		vector<int> a(n), b;
		rep(i, n) cin >> a[i];
		b = a;
		sort(all(b));
		int lid = (n-1) - x + 1, rid = x - 1;
		if (rid-lid < 0) cout << "YES" << endl;
		else {
			bool ok = true;
			rep3(i, lid, rid+1) if (a[i] != b[i]) ok = false;
			if (ok) cout << "YES" << endl;
			else cout << "NO" << endl;
		}
	}
	return 0;
}
