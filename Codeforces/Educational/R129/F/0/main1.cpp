// 解説AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector<vector<pair<int, int>>> g(n);
	rep(i, n-1) {
		int vi, ui, xi;
		cin >> vi >> ui >> xi;
		--vi; --ui; --xi;
		g[vi].emplace_back(ui, xi);
		g[ui].emplace_back(vi, xi);
	}
	vector<int> tsz(n), din(n, -1), dout(n, -1), par(n, -1), dord;
	auto init = [&](auto init, int vi=0, int did=0) -> int {
		din[vi] = did;
		dord.push_back(vi);
		tsz[vi] = 1;
		if (!g[vi].empty()) {
			for (auto tpi : g[vi]) if (din[tpi.first] == -1) {
				did = init(init, tpi.first, did+1);
				tsz[vi] += tsz[tpi.first];
				par[tpi.first] = tpi.second;
			}
		}
		return dout[vi] = did;
	};
	init(init);
	vector<vector<int>> xvlst(n, vector<int>(1, 0));
	for (int vi : dord) for (auto pi : g[vi]) xvlst[pi.second].push_back(vi);
	rep(i, n) xvlst[i].erase(unique(all(xvlst[i])), xvlst[i].end());
	ll res = 0;
	auto ischild = [&](int vi, int ti) -> bool {
		return (din[vi] <= din[ti] && dout[vi] >= dout[ti]);
	};
	vector<vector<int>> ng(n), dp(n, vector<int>(2));
	auto dfs = [&](auto dfs, int vi, int xi) -> ll {
		ll val = 0;
		if (!ng[vi].empty()) for (int ti : ng[vi]) val += dfs(dfs, ti, xi);
		dp[vi][0] = tsz[vi];
		dp[vi][1] = 0;
		if (!ng[vi].empty()) {
			for (int ti : ng[vi]) dp[vi][0] -= tsz[ti];
			for (int ti : ng[vi]) {
				if (par[ti] == xi) {
					val += (ll)dp[ti][0] * dp[vi][0];
					dp[vi][1] += dp[ti][0];
				}
				else {
					val += (ll)dp[ti][0] * dp[vi][1];
					val += (ll)dp[ti][1] * dp[vi][0];
					dp[vi][1] += dp[ti][1];
					dp[vi][0] += dp[ti][0];
				}
			}
		}
		return val;
	};
	rep(i, n) {
		stack<int> st;
		for (int vi : xvlst[i]) {
			while (!st.empty() && !ischild(st.top(), vi)) st.pop();
			if (!st.empty()) ng[st.top()].push_back(vi);
			st.push(vi);
		}
		res += dfs(dfs, 0, i);
		for (int vi : xvlst[i]) {
			ng[vi].clear();
			dp[vi][0] = dp[vi][1] = 0;
		}
	}
	cout << res << endl;
	return 0;
}
