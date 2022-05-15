// 

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
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t0;
	cin >> t0;
	rep(i0, t0) {
		int n, m;
		cin >> n >> m;
		vector<vector<int>> a(n, vector<int>(m));
		rep(i, n) rep(j, m) cin >> a[i][j];
		auto calc = [&](int yi, int xi) -> int {
			const vector<int> dy = { -1, -1, 1, 1 }, dx = { -1, 1, 1, -1 };
			int val = a[yi][xi];
			rep(i1, 4) {
				int ny = yi + dy[i1], nx = xi + dx[i1];
				while (ny>=0 && ny<n && nx>=0 && nx<m) {
					val += a[ny][nx];
					ny += dy[i1]; nx += dx[i1];
				}
			}
			return val;
		};
		int res = 0;
		rep(i, n) rep(j, m) res = max(res, calc(i, j));
		cout << res << endl;
	}
	return 0;
}
