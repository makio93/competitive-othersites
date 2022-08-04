// 本番AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const int INF = (int)(2e9);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t0;
	cin >> t0;
	rep(i0, t0) {
		int m;
		cin >> m;
		vector<vector<int>> a(2, vector<int>(m));
		rep(i, 2) rep(j, m) {
			cin >> a[i][j];
			if (a[i][j] == 0) a[i][j] = -1;
		}
		vector<vector<int>> lvals(2, vector<int>(m, INF)), rvals(2, vector<int>(m, INF));
		rep(i, 2) {
			int nval = -1;
			rep(j, m) {
				nval = max(nval, a[i][j]) + 1;
				lvals[i][j] = nval;
			}
		}
		rep(i, 2) {
			int nval = -1;
			repr(j, m) {
				nval = max(nval, a[i][j]) + 1;
				rvals[i][j] = nval;
			}
		}
		int res = INF, nval = -1;
		rep(i, m) {
			if (i%2 == 0) {
				nval = max(nval+1, a[0][i]+1);
				int tval = nval;
				tval = max(tval+(m-1)-i, lvals[0][m-1]);
				tval = max(tval+1, a[1][m-1]+1);
				tval = max(tval+(m-1)-i, rvals[1][i]);
				res = min(res, tval);
				nval = max(nval+1, a[1][i]+1);
			}
			else {
				nval = max(nval+1, a[1][i]+1);
				int tval = nval;
				tval = max(tval+(m-1)-i, lvals[1][m-1]);
				tval = max(tval+1, a[0][m-1]+1);
				tval = max(tval+(m-1)-i, rvals[0][i]);
				res = min(res, tval);
				nval = max(nval+1, a[0][i]+1);
			}
		}
		res = min(res, nval);
		cout << res << endl;
	}
	return 0;
}
