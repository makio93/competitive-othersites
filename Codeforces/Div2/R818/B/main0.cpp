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
		int n, k, r, c;
		cin >> n >> k >> r >> c;
		--r; --c;
		int tval = (r+c) % k;
		vector<string> res(n, string(n, '.'));
		rep(i, n) rep(j, n) if ((i+j)%k == tval) res[i][j] = 'X';
		rep(i, n) cout << res[i] << endl;
	}
	return 0;
}
