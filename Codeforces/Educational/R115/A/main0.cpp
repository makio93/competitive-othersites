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
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t0;
	cin >> t0;
	rep(i0, t0) {
		int n;
		cin >> n;
		vector<string> cells(2);
		rep(i, 2) cin >> cells[i];
		vector<vector<bool>> visited(2, vector<bool>(n));
		queue<pair<int, int>> que;
		que.emplace(0, 0);
		visited[0][0] = true;
		while (!que.empty()) {
			auto [y, x] = que.front(); que.pop();
			const vector<vector<int>> dy = { { 0, 1 }, { 0, -1 } };
			const vector<int> dx = { { 1, 1 } };
			rep(i2, 2) {
				int ny = y + dy[y][i2], nx = x + dx[i2];
				if (ny<0 || ny>=2 || nx<0 || nx>=n) continue;
				if (cells[ny][nx] == '1') continue;
				if (visited[ny][nx]) continue;
				que.emplace(ny, nx);
				visited[ny][nx] = true;
			}
		}
		if (visited[1][n-1]) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
