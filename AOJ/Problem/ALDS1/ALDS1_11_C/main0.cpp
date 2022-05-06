// 学習0回目,自力AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

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
	vector<int> dist(n, -1);
	queue<int> que;
	dist[0] = 0;
	que.push(0);
	while (!que.empty()) {
		int vi = que.front(); que.pop();
		int di = dist[vi], ndi = di + 1;
		for (int ti : g[vi]) if (dist[ti] == -1) {
			dist[ti] = ndi;
			que.push(ti);
		}
	}
	rep(i, n) cout << (i+1) << ' ' << dist[i] << endl;
	return 0;
}
