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
		vector<int> svals;
		int mval = n + n - 2, rval = 0;
		while (rval*rval <= mval) {
			svals.push_back(rval*rval);
			++rval;
		}
		vector<int> res(n, -1);
		int id = n-1, m = svals.size();
		bool ok = true;
		repr(i, m) {
			if (svals[i]-id < 0) {
				ok = false;
				break;
			}
			while (id>=0 && svals[i]-id<n && res[svals[i]-id]==-1) {
				res[svals[i]-id] = id;
				--id;
			}
			if (id < 0) break;
		}
		if (id >= 0) ok = false;
		if (ok) rep(i, n) cout << res[i] << (i<n-1?' ':'\n');
		else cout << -1 << endl;
	}
	return 0;
}
