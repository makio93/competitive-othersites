// 

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

int main() {
	while (1) {
		int w, h;
		cin >> w >> h;
		if (w==0 && h==0) break;
		vector<vector<bool>> c(h, vector<bool>(w));
		rep(i, h) rep(j, w) {
			int ci;
			cin >> ci;
			c[i][j] = ci == 1;
		}
		int res = 0;
		rep(i, h) rep(j, w) if (c[i][j]) {
			++res;
			auto dfs = [&](auto dfs, int yi, int xi) -> void {
				c[yi][xi] = false;
				rep3(dy, -1, 2) rep3(dx, -1, 2) {
					int ny = yi + dy, nx = xi + dx;
					if (ny<0 || ny>=h || nx<0 || nx>=w || !c[ny][nx]) continue;
					dfs(dfs, ny, nx);
				}
			};
			dfs(dfs, i, j);
		}
		cout << res << endl;
	}
	return 0;
}
