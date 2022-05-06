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
	int n;
	cin >> n;
	vector<vector<int>> g(n);
	rep(i, n) {
		int id, ki;
		cin >> id >> ki;
		--id;
		rep(j, ki) {
			int ti;
			cin >> ti;
			--ti;
			g[id].push_back(ti);
		}
	}
	vector<int> d(n), f(n);
	auto dfs = [&](auto dfs, int vi, int di) -> int {
		d[vi] = di;
		for (int ti : g[vi]) if (d[ti] == 0) di = dfs(dfs, ti, di+1);
		return (f[vi] = di + 1);
	};
	int di = 1;
	rep(i, n) if (d[i] == 0) di = dfs(dfs, i, di) + 1;
	rep(i, n) cout << (i+1) << ' ' << d[i] << ' ' << f[i] << endl;
	return 0;
}
