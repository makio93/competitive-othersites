// 自力AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const int INF = (int)(1e9);

const vector<int> dy = { -1, -1, 1, 1 }, dx = { -1, 1, 1, -1 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t0;
	cin >> t0;
	rep(i0, t0) {
		int n, m;
		cin >> n >> m;
		vector<string> s(n);
		rep(i, n) cin >> s[i];
		auto is_walk = [&](int yi, int xi) -> bool {
			const vector<int> tyi = { -1, 0, 1, 0 }, txi = { 0, 1, 0, -1 };
			rep(ii, 4) {
				int nyi = yi + tyi[ii], nxi = xi + txi[ii];
				if (nyi<0 || nyi>=n || nxi<0 || nxi>=m) continue;
				if (s[nyi][nxi] == '#') return false;
			}
			return true;
		};
		vector<vector<int>> dist(n, vector<int>(m, INF));
		vector<vector<pair<int, int>>> pre(n, vector<pair<int, int>>(m, make_pair(INF, INF)));
		deque<pair<int, int>> deq;
		rep(i, n) if (is_walk(i, 0)) {
			if (s[i][0] == '.') {
				dist[i][0] = 1;
				deq.emplace_back(i, 0);
				pre[i][0] = { -1, -1 };
			}
			else {
				dist[i][0] = 0;
				deq.emplace_front(i, 0);
				pre[i][0] = { -1, -1 };
			}
		}
		while (!deq.empty()) {
			auto pi = deq.front(); deq.pop_front();
			int yi = pi.first, xi = pi.second, di = dist[yi][xi];
			rep(ii, 4) {
				int nyi = yi + dy[ii], nxi = xi + dx[ii];
				if (nyi<0 || nyi>=n || nxi<0 || nxi>=m || !is_walk(nyi, nxi)) continue;
				int ndi = di;
				if (s[nyi][nxi] == '.') {
					++ndi;
					if (dist[nyi][nxi] <= ndi) continue;
					dist[nyi][nxi] = ndi;
					deq.emplace_back(nyi, nxi);
					pre[nyi][nxi] = { yi, xi };
				}
				else {
					if (dist[nyi][nxi] <= ndi) continue;
					dist[nyi][nxi] = ndi;
					deq.emplace_front(nyi, nxi);
					pre[nyi][nxi] = { yi, xi };
				}
			}
		}
		int res = INF;
		rep(i, n) res = min(res, dist[i][m-1]);
		if (res == INF) cout << "NO" << endl;
		else {
			cout << "YES" << endl;
			int yi = -1, xi = m - 1;
			rep(i, n) if (dist[i][m-1] == res) {
				yi = i;
				break;
			}
			auto rs = s;
			if (rs[yi][xi] == '.') rs[yi][xi] = '#';
			while (xi > 0) {
				int tyi = pre[yi][xi].first, txi = pre[yi][xi].second;
				if (rs[tyi][txi] == '.') rs[tyi][txi] = '#';
				yi = tyi; xi = txi;
			}
			rep(i, n) cout << rs[i] << endl;
		}
	}
	return 0;
}
