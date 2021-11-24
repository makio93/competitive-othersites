#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 本番中実装,WA

const int INF = (int)(1e9);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t0;
	cin >> t0;
	rep(i0, t0) {
		int n;
		cin >> n;
		vector<int> a(n), b(n);
		rep(i, n) cin >> a[i] >> b[i];
		vector<int> lvals(n), rvals(n);
		vector<int> ldp(n+1, INF), rdp(n+1, INF);
		rep(i, n) a[i] *= -1;
		int lval = 0, rval = 0;
		rep(i, n) {
			lvals[i] = min(lval, b[i]);
			if (a[i] != 0) {
				int di = distance(ldp.begin(), lower_bound(all(ldp), a[i]));
				lval = max(lval, di+1);
				ldp[di] = a[i];
			}
		}
		rep(i, n) a[i] *= -1;
		rep(i, n) b[i] *= -1;
		repr(i, n) {
			rvals[i] = min(rval, a[i]);
			if (b[i] != 0) {
				int di = distance(rdp.begin(), lower_bound(all(rdp), b[i]));
				rval = max(rval, di);
				rdp[di] = b[i];
			}
		}
		int res = 0;
		rep(i, n) res = max(res, lvals[i]+rvals[i]+1);
		cout << res << endl;
	}
	return 0;
}
