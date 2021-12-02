#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 本番,未完成

const vector<string> tar = { "crewmate", "imposter" };

struct UnionFind {
	vector<int> d;
	UnionFind(int n=0) : d(n, -1) {}
	int find(int x) {
		if (d[x] < 0) return x;
		return (d[x] = find(d[x]));
	}
	bool unite(int x, int y) {
		x = find(x); y = find(y);
		if (x == y) return false;
		if (d[x] > d[y]) swap(x, y);
		d[x] += d[y];
		d[y] = x;
		return true;
	}
	bool same(int x, int y) { return (find(x) == find(y)); }
	int size(int x) { return -d[find(x)]; }
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t0;
	cin >> t0;
	rep(i0, t0) {
		int n, m;
		cin >> n >> m;
		vector<unordered_map<int, int>> g(n);
		UnionFind d(n);
		bool ok = true;
		rep(i, m) {
			int ai, bi;
			string ci;
			cin >> ai >> bi >> ci;
			--ai; --bi;
			if (ai > bi) swap(ai, bi);
			int val = (ci == tar[0]) ? 0 : 1;
			if (g[ai].find(bi)!=g[ai].end() && g[ai][bi]!=val) ok = false;
			g[ai][bi] = val;
			d.unite(ai, bi);
		}
		if (!ok) {
			cout << -1 << endl;
			continue;
		}
		vector<bool> visited(n);
		vector<int> status(n, 1);
		int res = 0;
		function<int(int,int)> dfs = [&](int v, int p) -> int {
			visited[v] = true;
			int cnt = status[v];
			for (auto tp : g[v]) if (tp.first != p) {
				if (status[v] == 1) {
					if (tp.second == status[tp.first]) {
						if (visited[tp.first]) {
							ok = false;
							return -1;
						}
						status[tp.first] = 1 - status[tp.first];
					}
				}
				else {
					if (tp.second != status[tp.first]) {
						if (visited[tp.first]) {
							ok = false;
							return -1;
						}
					}
					status[tp.first] = 1 - status[tp.first];
				}
				if (!visited[tp.first]) {
					int rval = dfs(tp.first, v);
					if (rval == -1) return -1;
					cnt += rval;
				}
			}
			return cnt;
		};
		rep(i, n) if (!visited[i]) {
			if (d.size(i) == 1) {
				++res;
				continue;
			}
			int rval = dfs(i, -1);
			if (rval == -1) ok = false;
			if (!ok) break;
			int sval = d.size(i);
			// res += max(rval, sval-rval);
			res += rval;
		}
		if (!ok) {
			cout << -1 << endl;
			continue;
		}
		cout << res << endl;
	}
	return 0;
}
