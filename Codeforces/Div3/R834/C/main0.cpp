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
		int l, r, x, a, b;
		cin >> l >> r >> x >> a >> b;
		if (a == b) cout << 0 << endl;
		else if (abs(a-b) >= x) cout << 1 << endl;
		else {
			int mval = INF;
			if (a==l || abs(a-l)>=x) {
				int val = 0;
				if (a != l) ++val;
				if (l==b || abs(b-l)>=x) {
					if (l != b) ++val;
					mval = min(mval, val);
				}
				else if (l==r || abs(r-l)>=x) {
					if (l != r) ++val;
					if (r==b || abs(r-b)>=x) {
						if (r != b) ++val;
						mval = min(mval, val);
					}
				}
			}
			if (a==r || abs(a-r)>=x) {
				int val = 0;
				if (a != r) ++val;
				if (r==b || abs(b-r)>=x) {
					if (r != b) ++val;
					mval = min(mval, val);
				}
				else if (l==r || abs(r-l)>=x) {
					if (l != r) ++val;
					if (l==b || abs(l-b)>=x) {
						if (l != b) ++val;
						mval = min(mval, val);
					}
				}
			}
			if (mval == INF) cout << -1 << endl;
			else cout << mval << endl;
		}
	}
	return 0;
}
