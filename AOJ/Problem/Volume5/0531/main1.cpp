#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 解説AC1

int main() {
	int w, h;
	cin >> w >> h;
	while (w!=0 || h!=0) {
		int n;
		cin >> n;
		vector<int> x1(n), y1(n), x2(n), y2(n);
		rep(i, n) cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
		function<int(vector<int>&,vector<int>&,int)> comp = [](vector<int>& a, vector<int>& b, int m) -> int {
			vector<int> lst;
			lst.push_back(0);
			lst.push_back(m);
			for (int id : a) lst.push_back(id);
			for (int id : b) lst.push_back(id);
			sort(all(lst));
			lst.erase(unique(all(lst)), lst.end());
			for (int& id : a) id = distance(lst.begin(), lower_bound(all(lst), id));
			for (int& id : b) id = distance(lst.begin(), lower_bound(all(lst), id));
			return lst.size() - 1;
		};
		w = comp(x1, x2, w);
		h = comp(y1, y2, h);
		vector<vector<int>> sub(h+1, vector<int>(w+1));
		rep(i, n) {
			sub[y1[i]][x1[i]]++;
			sub[y2[i]][x1[i]]--;
			sub[y1[i]][x2[i]]--;
			sub[y2[i]][x2[i]]++;
		}
		rep(i, w+1) rep(j, h) sub[j+1][i] += sub[j][i];
		rep(i, h) rep(j, w) sub[i][j+1] += sub[i][j];
		vector<vector<bool>> visited(h, vector<bool>(w));
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
