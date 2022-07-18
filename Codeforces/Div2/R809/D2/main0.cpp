// 本番WA

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
		int n, k;
		cin >> n >> k;
		vector<int> a(n);
		rep(i, n) cin >> a[i];
		if (a[n-1]/k == 0) {
			cout << 0 << endl;
			continue;
		}
		int res = INF;
		pair<int, pair<int, int>> mkval = { -1, { -1, -1 } };
		rep(i, n) rep3(ki, 1, k+1) mkval = max(mkval, { a[i]%ki, { ki, i } });
		int id = mkval.second.second, ki = mkval.second.first, tval = a[id] / ki;
		multiset<tuple<int, int, int>> ast;
		rep(j, n) {
			int pi = (tval>0 ? min(k, (a[j]+tval-1)/tval) : k);
			ast.emplace(a[j]/pi, a[j], pi);
		}
		res = min(res, get<0>(*ast.rbegin())-get<0>(*ast.begin()));
		rep(j, n) {
			auto titr = ast.begin();
			int ai = get<1>(*titr), pi = get<2>(*titr);
			ast.erase(ast.begin());
			if (pi-1 < 1) break;
			ast.emplace(ai/(pi-1), ai, pi-1);
			res = min(res, get<0>(*ast.rbegin())-get<0>(*ast.begin()));
		}
		cout << res << endl;
	}
	return 0;
}
