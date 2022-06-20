// 解説AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const int INF = (int)(1.5e9);

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
		pair<int, pair<int, int>> mval = { -INF, { -1, -1 } };
		rep(i, n) rep(j, m) mval = max(mval, { a[i][j], { i, j } });
		int y = mval.second.first, x = mval.second.second;
		cout << (max(y+1, n-y) * max(x+1, m-x)) << endl;
	}
	return 0;
}
