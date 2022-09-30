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
		vector<vector<int>> g(n);
		rep3(i, 1, n) {
			int pi;
			cin >> pi;
			--pi;
			g[pi].push_back(i);
			g[i].push_back(pi);
		}
		int lval = 0, rval = n;
		while (rval-lval > 1) {
			int cval = rval - (rval-lval) / 2;
			int kcnt = 0;
			auto dfs = [&](auto dfs, int di=0, int vi=0, int pi=-1) -> void {
				for (int& ti : g[vi]) if (ti != pi) {
					if (di+1 > cval) {
						++kcnt;
						dfs(dfs, 1, ti, vi);
					}
					else dfs(dfs, di+1, ti, vi);
				}
			};
			dfs(dfs);
			if (kcnt <= k) rval = cval;
			else lval = cval;
		}
		cout << rval << endl;
	}
	return 0;
}
