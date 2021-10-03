#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 本番WA,2

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
		vector<vector<int>> g(n);
		vector<int> deg(n);
		rep(i, n-1) {
			int ui, vi;
			cin >> ui >> vi;
			--ui; --vi;
			g[ui].push_back(vi);
			g[vi].push_back(ui);
			deg[ui]++; deg[vi]++;
		}
		int xsum = 0;
		rep(i, n) xsum ^= a[i];
		if (xsum!=0 && k<=2) {
			cout << "NO" << endl;
			continue;
		}
		bool even = false;
		if (xsum == 0) {
			int tmp = 0;
			rep(i, n) tmp |= a[i];
			xsum = tmp;
			even = true;
		}
		vector<bool> visited(n);
		function<bool(int,int,int)> dfs = [&](int v, int p, int val) -> bool {
			val ^= a[v];
			visited[v] = true;
			if (val == xsum) return true;
			for (int ti : g[v]) if (ti!=p && !visited[ti]) {
				bool ret = dfs(ti, v, val);
				if (ret) return true;
			}
			return false;
		};
		bool res = false;
		if (even) {
			rep(i, n) if (!visited[i] && deg[i]==1) if (dfs(i, -1, 0)) res = true;
		}
		else {
			int okcnt = 0;
			rep(i, n) if (!visited[i] && deg[i]==1) if (dfs(i, -1, 0)) ++okcnt;
			res = (okcnt >= 2);
		}
		if (res) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
