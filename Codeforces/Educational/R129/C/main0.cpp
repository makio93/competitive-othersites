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
	int t0;
	cin >> t0;
	rep(i0, t0) {
		int n;
		cin >> n;
		vector<int> a(n), b(n);
		rep(i, n) cin >> a[i];
		rep(i, n) cin >> b[i];
		vector<pair<int, int>> res;
		rep(i, n-1) {
			tuple<int, int, int> mval = { a[i], b[i], i };
			rep3(j, i+1, n) mval = min(mval, { a[j], b[j], j });
			if (get<2>(mval) != i) {
				int id = get<2>(mval);
				swap(a[i], a[id]);
				swap(b[i], b[id]);
				res.emplace_back(i, id);
			}
		}
		bool ok = true;
		rep(i, n-1) if (b[i+1] < b[i]) ok = false;
		if (ok) {
			int m = res.size();
			cout << m << endl;
			if (m > 0) rep(i, m) cout << (res[i].first+1) << ' ' << (res[i].second+1) << endl;
		}
		else cout << -1 << endl;
	}
	return 0;
}
