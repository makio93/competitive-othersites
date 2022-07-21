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
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	vector<vector<int>> g(n);
	rep(i, n-1) {
		int xi, yi;
		cin >> xi >> yi;
		--xi; --yi;
		g[xi].push_back(yi);
		g[yi].push_back(xi);
	}
	vector<int> bcnt(30), mcnt(30);
	auto dfs = [&](auto dfs, int vi=0, int pi=-1) -> void {
		rep(i, 30) if ((a[vi]>>i)&1) bcnt[i]++;
		bool leaf = true;
		for (int ti : g[vi]) if (ti != pi) {
			leaf = false;
			dfs(dfs, ti, vi);
		}
		if (leaf) rep(i, 30) mcnt[i] = max(mcnt[i], bcnt[i]);
		rep(i, 30) if ((a[vi]>>i)&1) bcnt[i]--;
	};
	dfs(dfs);
	int res = INF;
	rep(i, 30) res = min(res, mcnt[i]);
	cout << (res-1) << endl;
	return 0;
}
