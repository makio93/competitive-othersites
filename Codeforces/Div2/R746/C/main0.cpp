#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 本番WA,1

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
		rep(i, n-1) {
			int ui, vi;
			cin >> ui >> vi;
			--ui; --vi;
			g[ui].push_back(vi);
			g[vi].push_back(ui);
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
		int rcnt = 0;
		function<int(int,int)> dfs = [&](int v, int p) -> int {
			int res = a[v];
			for (int ti : g[v]) if (ti != p) res ^= dfs(ti, v);
			if (res == xsum) {
				++rcnt;
				res = 0;
			}
			return res;
		};
		int pcnt = 0;
		function<int(int,int,int)> dfs2 = [&](int v, int p, int val) -> int {
			int pval = val ^ a[v];
			if (pval == xsum) {
				++pcnt;
				pval = 0;
			}
			int res = a[v];
			for (int ti : g[v]) if (ti != p) res ^= dfs2(ti, v, pval);
			if (res == xsum) {
				++rcnt;
				res = 0;
			}
			return res;
		};
		if (!even) dfs(0, -1);
		else dfs2(0, -1, 0);
		if ((even&&(pcnt>=1||rcnt>=1)) || ((!even)&&rcnt>1)) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
