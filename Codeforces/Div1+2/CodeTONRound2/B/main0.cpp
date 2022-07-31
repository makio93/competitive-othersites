// 本番AC

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
		int n, x;
		cin >> n >> x;
		vector<int> a(n);
		rep(i, n) cin >> a[i];
		int res = 0, mx = a[0], mn = a[0];
		rep3(i, 1, n) {
			mx = max(mx, a[i]);
			mn = min(mn, a[i]);
			if (mx-mn > 2*x) {
				++res;
				mx = a[i];
				mn = a[i];
			}
		}
		cout << res << endl;
	}
	return 0;
}
