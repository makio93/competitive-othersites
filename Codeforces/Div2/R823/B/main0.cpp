// 本番TLE

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
		vector<int> x(n), t(n);
		rep(i, n) cin >> x[i];
		rep(i, n) cin >> t[i];
		double lval = 0.0, rval = 1e9;
		map<double, int> sub;
		while (abs(rval-lval) > 1e-6) {
			double cval = lval + (rval-lval) / 2.0;
			sub.clear();
			rep(i, n) {
				double di = cval-t[i];
				if (di <= 0.0) continue;
				sub[x[i]-di]++;
				sub[x[i]+di]--;
			}
			int rcnt = 0, mval = 0;
			for (auto& pi : sub) {
				rcnt += pi.second;
				mval = max(mval, rcnt);
			}
			if (mval == n) rval = cval;
			else lval = cval;
		}
		sub.clear();
		rep(i, n) {
			double di = rval-t[i];
			sub[x[i]-di]++;
			sub[x[i]+di]--;
		}
		int rcnt = 0;
		double xid = 0.0;
		for (auto& pi : sub) {
			rcnt += pi.second;
			if (rcnt == n) xid = pi.first;
		}
		cout << fixed << setprecision(6) << xid << endl;
	}
	return 0;
}
