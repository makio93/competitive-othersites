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
		int n;
		cin >> n;
		int xl = 0, xr = 0, yl = 0, yr = 0;
		rep(i, n) {
			int xi, yi;
			cin >> xi >> yi;
			if (xi != 0) {
				xl = min(xl, xi);
				xr = max(xr, xi);
			}
			else {
				yl = min(yl, yi);
				yr = max(yr, yi);
			}
		}
		int res = abs(xr-xl)*2 + abs(yr-yl)*2;
		cout << res << endl;
	}
	return 0;
}
