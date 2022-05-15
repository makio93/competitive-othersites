// 

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
		vector<vector<int>> g(n);
		rep3(i, 1, n) {
			int ai;
			cin >> ai;
			--ai;
			g[ai].push_back(i);
		}
		string s;
		cin >> s;
		vector<int> vals(n);
		auto dfs = [&](auto dfs, int vi=0) -> int {
			int val = (s[vi] == 'B') ? 1 : -1;
			for (int ti : g[vi]) val += dfs(dfs, ti);
			return vals[vi] = val;
		};
		dfs(dfs);
		int res = 0;
		rep(i, n) if (vals[i] == 0) ++res;
		cout << res << endl;
	}
	return 0;
}
