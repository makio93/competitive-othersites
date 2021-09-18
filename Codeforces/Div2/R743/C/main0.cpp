#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 本番AC

int main() {
	int t0;
	cin >> t0;
	rep(i0, t0) {
		int n;
		cin >> n;
		vector<set<int>> g(n);
		rep(i, n) {
			int ki;
			cin >> ki;
			rep(j, ki) {
				int ai;
				cin >> ai;
				--ai;
				g[ai].insert(i);
			}
		}
		vector<int> din(n);
		rep(i, n) for (int ti : g[i]) din[ti]++;
		vector<int> dist(n);
		queue<int> que;
		unordered_set<int> finished;
		rep(i, n) if (din[i] == 0) {
			que.push(i);
			dist[i] = 1;
			finished.insert(i);
		}
		if (finished.empty()) {
			cout << -1 << endl;
			continue;
		}
		while (!que.empty()) {
			int v = que.front(); que.pop();
			int d = dist[v];
			for (int ti : g[v]) {
				din[ti]--;
				int nd = d;
				if (ti < v) ++nd;
				dist[ti] = max(dist[ti], nd);
				if (din[ti] == 0) {
					que.push(ti);
					finished.insert(ti);
				}
			}
		}
		if ((int)(finished.size()) < n) cout << -1 << endl;
		else {
			int res = 0;
			rep(i, n) res = max(res, dist[i]);
			cout << res << endl;
		}
	}
	return 0;
}
