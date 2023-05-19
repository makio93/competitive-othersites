// 本番AC

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
	int n, m, q;
	cin >> n >> m;
	vector<int> a(m);
	rep(i, m) cin >> a[i];
	ll res = 0;
	rep(i, m) res += (ll)a[i] * a[i];
	cin >> q;
	rep(i, q) {
		int ci, ki, di;
		cin >> ci >> ki >> di;
		--ci; --di;
		res -= (ll)a[ci] * a[ci] + (ll)a[di] * a[di];
		a[ci] -= ki;
		a[di] += ki;
		res += (ll)a[ci] * a[ci] + (ll)a[di] * a[di];
		cout << res << endl;
	}
	return 0;
}
