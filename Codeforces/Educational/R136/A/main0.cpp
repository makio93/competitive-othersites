// 本番AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const int INF = (int)(1e9);
vector<int> dy = { -2, -2, -1, 1, 2, 2, 1, -1 }, dx = { -1, 1, 2, 2, 1, -1, -2, -2 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t0;
	cin >> t0;
	rep(i0, t0) {
		int n, m;
		cin >> n >> m;
		pair<int, int> res = { -1, -1 };
		rep(i, n) {
			rep(j, m) {
				bool ok = false;
				rep(i2, 8) {
					int ny = i + dy[i2], nx = j + dx[i2];
					if (ny>=0 && ny<n && nx>=0 && nx<m) {
						ok = true;
						break;
					}
				}
				if (!ok) {
					res = { i+1, j+1 };
					break;
				}
			}
			if (res.first != -1) break;
		}
		if (res.first == -1) res = { 1, 1 };
		cout << res.first << ' ' << res.second << endl;
	}
	return 0;
}
