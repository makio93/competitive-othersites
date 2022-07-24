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
		int n, m, k;
		cin >> n >> m >> k;
		vector<int> a(k);
		rep(i, k) cin >> a[i];
		sort(a.rbegin(), a.rend());
		int rcnt = m;
		ll asum = 0;
		rep(i, k) {
			if (a[i] >= (ll)n*2) {
				rcnt -= 2;
				if (a[i] >= (ll)n*3) asum += a[i] / n - 2;
			}
			if (rcnt <= 1) break;
		}
		if (rcnt <= asum) {
			cout << "Yes" << endl;
			continue;
		}
		rcnt = n; asum = 0;
		rep(i, k) {
			if (a[i] >= (ll)m*2) {
				rcnt -= 2;
				if (a[i] >= (ll)m*3) asum += a[i] / m - 2;
			}
			if (rcnt <= 1) break;
		}
		if (rcnt <= asum) {
			cout << "Yes" << endl;
			continue;
		}
		cout << "No" << endl;
	}
	return 0;
}
