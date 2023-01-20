// 解説AC

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const int INF = (int)(1e9);

int main() {
	int n;
	cin >> n;
	vector<vector<int>> ab(n*2, vector<int>(2)), xy(n, vector<int>(2));
	rep(i, n*2) cin >> ab[i][0];
	rep(i, n*2) cin >> ab[i][1];
	rep(i, n) cin >> xy[i][0];
	rep(i, n) cin >> xy[i][1];
	ll res = 0;
	rep(i, n) {
		ll mval = 0;
		rep(j1, 2) rep(j2, 2) mval = max(mval, (ll)ab[i*2][j1]+ab[i*2+1][j2]+xy[i][j1^j2]);
		res += mval;
	}
	cout << res << endl;
	return 0;
}
