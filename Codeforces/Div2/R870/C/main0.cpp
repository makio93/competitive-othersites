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
		int n, m;
		cin >> n >> m;
		if (n==1 || m==1) {
			cout << "YES" << endl;
			continue;
		}
		if (n <= m) {
			cout << "NO" << endl;
			continue;
		}
		bool res = true;
		for (int i=1; i*i<=n&&i<=m; ++i) if (n%i == 0) {
			if (i<=m && i>1) {
				res = false;
				break;
			}
			if (n/i<=m && n/i>1) {
				res = false;
				break;
			}
		}
		if (res) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
