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
		int a, b, n, m;
		cin >> a >> b >> n >> m;
		ll res = 0;
		int pval = n / (m+1), rval = n % (m+1);
		if ((ll)m*a <= (ll)(m+1)*b) res += (ll)m * a * pval;
		else res += (ll)(m+1) * b * pval;
		if (a <= b) res += (ll)rval * a;
		else res += (ll)rval * b;
		cout << res << endl;
	}
	return 0;
}
