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
		vector<vector<pair<int, pair<int, int>>>> g(n);
		rep3(i, 1, n) {
			int pi, ai, bi;
			cin >> pi >> ai >> bi;
			--pi;
			g[pi].emplace_back(i, make_pair(ai, bi));
		}
		vector<int> res(n);
		ll aval = 0;
		vector<ll> blst;
		blst.push_back(0);
		auto dfs = [&](auto dfs, int vi=0) -> void {
			for (auto tpi : g[vi]) {
				int ti = tpi.first, tai = tpi.second.first, tbi = tpi.second.second;
				aval += tai;
				blst.push_back(blst.back()+tbi);
				int nbl = upper_bound(all(blst), aval) - blst.begin() - 1;
				res[ti] = nbl;
				dfs(dfs, ti);
				blst.pop_back();
				aval -= tai;
			}
		};
		dfs(dfs);
		rep3(i, 1, n) cout << res[i] << (i<n-1?' ':'\n');
	}
	return 0;
}
