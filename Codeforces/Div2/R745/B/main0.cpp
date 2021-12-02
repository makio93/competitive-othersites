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
		ll n, m, k;
		cin >> n >> m >> k;
		if (k < 2) cout << "NO" << endl;
		else if (k-2 == 0) {
			if (n==1 && m==0) cout << "YES" << endl;
			else cout << "NO" << endl;
		}
		else if (k-2 == 1) {
			if (n == 1) {
				if (m == 0) cout << "YES" << endl;
				else cout << "NO" << endl;
			}
			else {
				ll mval = n * (n-1) / 2;
				if (m == mval) cout << "YES" << endl;
				else cout << "NO" << endl;
			}
		}
		else {
			if (n == 1) {
				if (m == 0) cout << "YES" << endl;
				else cout << "NO" << endl;
			}
			else {
				ll mval = n * (n-1) / 2, lval = n - 1;
				if (m>mval || m<lval) {
					cout << "NO" << endl;
					continue;
				}
				ll aval = (m + (k-3)) / (k-2);
				ll nval = round(sqrt(2*aval));
				while (nval*(nval-1) < 2*aval) ++nval;
				ll bval = nval + nval * (nval-1) / 2 * (k-3);
				ll sval = bval - n;
				ll tmval = aval - sval;
				if (m >= tmval) cout << "YES" << endl;
				else cout << "NO" << endl;
			}
		}
	}
	return 0;
}
