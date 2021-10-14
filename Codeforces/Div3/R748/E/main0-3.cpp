#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 本番WA3

const int INF = (int)(1e9);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t0;
	cin >> t0;
	rep(i0, t0) {
		int n, k;
		cin >> n >> k;
		vector<unordered_set<int>> g(n);
		rep(i, n-1) {
			int ai, bi;
			cin >> ai >> bi;
			--ai; --bi;
			g[ai].insert(bi);
			g[bi].insert(ai);
		}
		map<int, unordered_set<int>> deg;
		rep(i, n) deg[g[i].size()].insert(i);
		bool zero = false;
		rep(i, k) {
			auto ndeg = deg;
			auto ng = g;
			bool ok = false;
			for (auto ti : deg[1]) {
				for (auto ti2 : g[ti]) {
					int gi = ng[ti2].size();
					ndeg[gi].erase(ti2);
					ng[ti].erase(ti2);
					ng[ti2].erase(ti);
					ndeg[gi-1].insert(ti2);
					ok = true;
				}
				ndeg[1].erase(ti);
			}
			swap(deg, ndeg);
			swap(ng, g);
			if (!ok) {
				zero = true;
				break;
			}
			if (deg.empty()) break;
		}
		int res = 0;
		unordered_set<int> vlst;
		if (!deg.empty() && !zero) {
			for (auto pi : deg) for (auto pi2 : pi.second) vlst.insert(pi2);
			res = vlst.size();
		}
		cout << res << endl;
	}
	return 0;
}
