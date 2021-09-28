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
		int n, m, k;
		cin >> n >> m >> k;
		vector<string> board(n);
		rep(i, n) cin >> board[i];
		rep3(i1, k, n) {
			for (int i=0; i+i1<n; ++i) for (int j=0; j+i1*2<m; ++j) {
				bool ok = true;
				int pi = i + i1, pj = j + i1;
				rep(i2, i1+1) {
					if (board[pi-i2][pj+i2] == '.') ok = false;
					if (board[pi-i2][pj-i2] == '.') ok = false;
				}
				if (ok) rep(i2, i1+1) board[pi-i2][pj+i2] = board[pi-i2][pj-i2] = '+';
			}
		}
		bool res = true;
		rep(i, n) rep(j, m) if (board[i][j] == '*') res = false;
		if (res) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
