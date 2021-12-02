#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 本番WA2

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
		rep(i, n-1) {
			int ai, bi;
			cin >> ai >> bi;
			--ai; --bi;
			g[ai].push_back(bi);
			g[bi].push_back(ai);
		}
		vector<int> deg(n);
		rep(i, n) deg[i] = g[i].size();
		vector<int> dist(n, -1);
		queue<int> que;
		rep(i, n) if (deg[i] == 1) {
			dist[i] = 0;
			que.push(i);
			deg[i]--;
		}
		while (!que.empty()) {
			int v = que.front(); que.pop();
			int d = dist[v], nd = d + 1;
			for (int ti : g[v]) if (deg[ti] > 0) {
				deg[ti]--;
				if (dist[ti] < nd) {
					dist[ti] = nd;
					que.push(ti);
				}
			}
		}
		int res = 0;
		rep(i, n) if (dist[i] >= k) ++res;
		cout << res << endl;
	}
	return 0;
}
