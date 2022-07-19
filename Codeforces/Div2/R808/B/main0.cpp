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
		int n, l, r;
		cin >> n >> l >> r;
		bool ok = true;
		vector<int> res(n);
		rep3(i, 1, n+1) {
			int val = r / i * i;
			if (val < l) {
				ok = false;
				break;
			}
			res[i-1] = val;
		}
		if (ok) {
			cout << "YES" << endl;
			rep(i, n) cout << res[i] << (i<n-1?' ':'\n');
		}
		else cout << "NO" << endl;
	}
	return 0;
}
