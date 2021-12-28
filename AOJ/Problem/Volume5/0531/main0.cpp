#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 自力AC

int main() {
	int w, h;
	cin >> w >> h;
	while (w!=0 || h!=0) {
		int n;
		cin >> n;
		vector<int> x1(n), y1(n), x2(n), y2(n);
		rep(i, n) cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
		vector<int> xlst, ylst;
		xlst.push_back(0);
		xlst.push_back(w);
		ylst.push_back(0);
		ylst.push_back(h);
		rep(i, n) xlst.push_back(x1[i]);
		rep(i, n) xlst.push_back(x2[i]);
		rep(i, n) ylst.push_back(y1[i]);
		rep(i, n) ylst.push_back(y2[i]);
		sort(all(xlst));
		xlst.erase(unique(all(xlst)), xlst.end());
		sort(all(ylst));
		ylst.erase(unique(all(ylst)), ylst.end());
		rep(i, n) x1[i] = distance(xlst.begin(), find(all(xlst), x1[i]));
		rep(i, n) x2[i] = distance(xlst.begin(), find(all(xlst), x2[i]));
		rep(i, n) y1[i] = distance(ylst.begin(), find(all(ylst), y1[i]));
		rep(i, n) y2[i] = distance(ylst.begin(), find(all(ylst), y2[i]));
		w = xlst.size() - 1;
		h = ylst.size() - 1;
		vector<vector<int>> sub(h, vector<int>(w+1));
		rep(i, n) {
			rep3(j, y1[i], y2[i]) {
				sub[j][x1[i]]++;
				sub[j][x2[i]]--;
			}
		}
		rep(i, h) rep(j, w) sub[i][j+1] += sub[i][j];
		vector<vector<bool>> visited(h, vector<bool>(w+1));
		int res = 0;
		rep(i, h) rep(j, w) if (sub[i][j]==0 && !visited[i][j]) {
			++res;
			queue<pair<int, int>> que;
			visited[i][j] = true;
			que.emplace(i, j);
			while (!que.empty()) {
				auto pi = que.front(); que.pop();
				int y = pi.first, x = pi.second;
				vector<int> dy = { 1, 0, -1, 0 }, dx = { 0, 1, 0, -1 };
				rep(i2, 4) {
					int ny = y + dy[i2], nx = x + dx[i2];
					if (ny<0 || ny>=h || nx<0 || nx>=w || sub[ny][nx]!=0 || visited[ny][nx]) continue;
					visited[ny][nx] = true;
					que.emplace(ny, nx);
				}
			}
		}
		cout << res << endl;
		cin >> w >> h;
	}
	return 0;
}
