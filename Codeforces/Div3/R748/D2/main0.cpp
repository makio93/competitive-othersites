#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 本番WA

ll gcd(ll a, ll b) { return (b ? gcd(b, a%b) : a); }

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t0;
	cin >> t0;
	rep(i0, t0) {
		int n;
		cin >> n;
		vector<int> a(n);
		rep(i, n) cin >> a[i];
		int mval = (int)(1e9);
		rep(i, n) mval = min(mval, a[i]);
		rep(i, n) a[i] -= mval;
		sort(all(a));
		int zcnt = 0;
		rep(i, n) if (a[i] == 0) ++zcnt;
		if (zcnt >= n/2) {
			cout << -1 << endl;
			continue;
		}
		unordered_map<int, int> gvals;
		rep3(i, zcnt, n) {
			unordered_map<int, int> nvals;
			nvals[a[i]] = 1;
			for (auto pi : gvals) {
				int gv = gcd(pi.first, a[i]);
				if (nvals.find(gv) == nvals.end()) nvals[gv] = pi.second + 1;
				else nvals[gv] = max(nvals[gv], pi.second+1);
			}
			for (auto pi : nvals) {
				if (gvals.find(pi.first) == gvals.end()) gvals[pi.first] = pi.second;
				else gvals[pi.first] = max(gvals[pi.first], pi.second);
			}
		}
		int res = 0;
		for (auto pi : gvals) if (pi.second >= n/2-zcnt) res = max(res, pi.first);
		cout << res << endl;
	}
	return 0;
}
