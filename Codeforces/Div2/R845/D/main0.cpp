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
const ll mod = (ll)(1e9) + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t0;
	cin >> t0;
	rep(i0, t0) {
		int n;
		cin >> n;
		vector<vector<int>> g(n);
		rep(i, n-1) {
			int ui, vi;
			cin >> ui >> vi;
			--ui; --vi;
			g[ui].push_back(vi);
			g[vi].push_back(ui);
		}
		vector<vector<ll>> dp(n, vector<ll>(2));
		auto dfs0 = [&](auto dfs0, int vi=0, int pi=-1) -> void {
			ll rval = 1;
			for (const int& ti : g[vi]) if (ti != pi) {
				dfs0(dfs0, ti, vi);
				ll tval = (dp[ti][0] + dp[ti][1]) % mod;
				rval = rval * tval % mod;
			}
			dp[vi][0] = dp[vi][1] = rval;
		};
		dfs0(dfs0);
		auto dfs1 = [&](auto dfs1, int vi=0, int pi=-1) -> void {
			vector<ll> vals(2), nvals;
			vals[0] = 1;
			bool leaf = true;
			for (const int& ti : g[vi]) if (ti != pi) {
				if (leaf) leaf = false;
				dfs1(dfs1, ti, vi);
				nvals.assign(2, 0);
				rep(i1, 2) rep(i2, 2) nvals[i1^i2] = (nvals[i1^i2] + vals[i1] * dp[ti][i2]) % mod;
				swap(vals, nvals);
			}
			if (!leaf) rep(i1, 2) dp[vi][i1] = (dp[vi][i1] + vals[i1]) % mod;
		};
		dfs1(dfs1);
		ll res = 0;
		auto dfs2 = [&](auto dfs2, ll mul=1LL, int vi=0, int pi=-1) -> void {
			res = (res + dp[vi][1] * mul) % mod;
			for (const int& ti : g[vi]) if (ti != pi) dfs2(dfs2, mul*2%mod, ti, vi);
		};
		dfs2(dfs2);
		cout << res << endl;
	}
	return 0;
}
