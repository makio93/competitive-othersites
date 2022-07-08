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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t0;
	cin >> t0;
	rep(i0, t0) {
		vector<vector<int>> a(2, vector<int>(2));
		rep(i, 2) rep(j, 2) cin >> a[i][j];
		int sum = 0;
		rep(i, 2) rep(j, 2) sum += a[i][j];
		if (sum == 0) cout << 0 << endl;
		else if (sum < 4) cout << 1 << endl;
		else cout << 2 << endl;
	}
	return 0;
}
