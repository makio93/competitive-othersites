// 学習0回目,解説AC

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
		cin.ignore();
		if (w==0 && h==0) break;
		vector<string> mat(h*2-1);
		rep(i, h*2-1) getline(cin, mat[i]);
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
				if (ny<0 || ny>=h || nx<0 || nx>=w || mat[yi+ny][xi+nx]=='1' || dist[ny][nx]!=INF) continue;
				dist[ny][nx] = ndi;
				que.emplace(ny, nx);
			}
		}
		if (dist[h-1][w-1] == INF) cout << 0 << endl;
		else cout << dist[h-1][w-1] << endl;
	}
	return 0;
}
