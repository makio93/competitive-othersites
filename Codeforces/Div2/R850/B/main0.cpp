// 本番AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const int INF = (int)(1.5e9);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t0;
	cin >> t0;
	rep(i0, t0) {
		int n, w, h;
		cin >> n >> w >> h;
		vector<int> a(n), b(n);
		rep(i, n) cin >> a[i];
		rep(i, n) cin >> b[i];
		int sub = (b[0]+h) - (a[0]+w), rval = 0, lval = INF;
		rep(i, n) {
			rval = max(rval, (b[i]+h)-(a[i]+sub+w));
			lval = min(lval, (b[i]-h)-(a[i]+sub-w));
		}
		if (rval <= lval) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
