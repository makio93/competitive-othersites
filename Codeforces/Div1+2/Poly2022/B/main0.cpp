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
		vector<int> a(m);
		rep(i, m) cin >> a[i];
		sort(a.rbegin(), a.rend());
		int pval = n / k, rval = n % k;
		bool ok = true;
		rep(i, m) {
			if (rval > 0) {
				if (a[i] > pval+1) {
					ok = false;
					break;
				}
				--rval;
			}
			else {
				if (a[i] > pval) {
					ok = false;
					break;
				}
			}
		}
		if (ok) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
