#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 本番WA

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t0;
	cin >> t0;
	rep(i0, t0) {
		int n, m;
		cin >> n >> m;
		vector<string> cells(n);
		rep(i, n) cin >> cells[i];
		vector<vector<int>> g((n+2)*(m+2));
		vector<int> deg((n+2)*(m+2));
		const string op = "LRUD";
		const vector<int> dy = { 0, 0, -1, 1 }, dx = { -1, 1, 0, 0 };
		rep(i, n) rep(j, m) {
			rep(j2, 4) if (cells[i][j] == op[j2]) {
				int y = i+1, x = j+1, ny = y + dy[j2], nx = x + dx[j2];
				g[ny*(m+2)+nx].push_back(y*(m+2)+x);
				deg[y*(m+2)+x]++;
				break;
			}
		}
		vector<int> dist((n+2)*(m+2), -1);
		queue<int> que;
		rep(i, (n+2)*(m+2)) if (deg[i] == 0) {
			dist[i] = (i%(m+2)>=1&&i%(m+2)<=m) ? 1 : 0;
			que.push(i);
		}
		do {
			while (!que.empty()) {
				int v = que.front(); que.pop();
				int d = dist[v];
				for (int ti : g[v]) {
					if (deg[ti] == 0) {
						dist[ti] = max(dist[ti], d+1);
						continue;
					}
					deg[ti]--;
					dist[ti] = max(dist[ti], d+1);
					if (deg[ti] > 0) continue;
					que.push(ti);
				}
			}
			rep(i, (n+2)*(m+2)) if (deg[i] == 1) {
				deg[i]--;
				que.push(i);
				dist[i] = max(1, dist[i]+1);
			}
		} while (!que.empty());
		pair<int, pair<int, int>> mval = { -1, { -1, -1 } };
		rep3(i, 1, n+1) rep3(j, 1, m+1) mval = max(mval, { dist[i*(m+2)+j], make_pair(i, j) });
		cout << mval.second.first << ' ' << mval.second.second << ' ' << mval.first << endl;
	}
	return 0;
}
