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
		vector<int> tvals;
		for (int i=0; i<n-i-1; ++i) if (a[i] != a[n-i-1]) {
			tvals.push_back(a[i]);
			tvals.push_back(a[n-i-1]);
			break;
		}
		bool res = false;
		if (tvals.empty()) res = true;
		else {
			for (int tval : tvals) {
				vector<int> b;
				rep(i, n) if (a[i] != tval) b.push_back(a[i]);
				bool ok = true;
				int m = b.size();
				for (int i=0; i<m-i-1; ++i) if (b[i] != b[m-i-1]) ok = false;
				if (ok) {
					res = true;
					break;
				}
			}
		}
		if (res) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
