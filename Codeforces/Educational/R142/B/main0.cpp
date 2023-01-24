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
		int a1, a2, a3, a4;
		cin >> a1 >> a2 >> a3 >> a4;
		if (a1 == 0) {
			cout << 1 << endl;
			continue;
		}
		int tval = min(a2, a3), res = a1 + tval * 2;
		a2 -= tval; a3 -= tval;
		int mval = max(a2, a3);
		if (a1 < mval) res += a1 + 1;
		else {
			res += mval;
			a1 -= mval;
			if (a4 <= a1) res += a4;
			else res += a1 + 1;
		}
		cout << res << endl;
	}
	return 0;
}
