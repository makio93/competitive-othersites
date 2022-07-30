// 学習0回目,自力AC

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
	while (1) {
		int w, h;
		cin >> w >> h;
		if (w==0 && h==0) break;
		vector<vector<bool>> rw(h, vector<bool>(w-1)), dw(h-1, vector<bool>(w));
		rep(i, h*2-1) {
			if (i%2 == 0) rep(j, w-1) {
				int val;
				cin >> val;
				rw[i/2][j] = val == 1;
			}
			else rep(j, w) {
				int val;
				cin >> val;
				dw[i/2][j] = val == 1;
			}
		}
		vector<vector<int>> dist(h, vector<int>(w, INF));
		queue<pair<int, int>> que;
		dist[0][0] = 1;
		que.emplace(0, 0);
		while (!que.empty()) {
			auto pi = que.front(); que.pop();
			int yi = pi.first, xi = pi.second, di = dist[yi][xi], ndi = di + 1;
			const vector<int> dy = { -1, 0, 1, 0 }, dx = { 0, 1, 0, -1 };
			rep(i1, 4) {
				int ny = yi + dy[i1], nx = xi + dx[i1];
				if (ny<0 || ny>=h || nx<0 || nx>=w) continue;
				if (i1%2 == 0) {
					int y1 = yi, y2 = ny;
					if (y1 > y2) swap(y1, y2);
					if (dw[y1][nx]) continue;
				}
				else {
					int x1 = xi, x2 = nx;
					if (x1 > x2) swap(x1, x2);
					if (rw[ny][x1]) continue;
				}
				if (dist[ny][nx] != INF) continue;
				dist[ny][nx] = ndi;
				que.emplace(ny, nx);
			}
		}
		if (dist[h-1][w-1] == INF) cout << 0 << endl;
		else cout << dist[h-1][w-1] << endl;
	}
	return 0;
}
