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

const ll mod = 998244353LL;
using mint = modint998244353;

int main() {
	ll n;
	int m;
	cin >> n >> m;
	if (m > n) {
		cout << 0 << endl;
		return 0;
	}
	mint a = 1, b = 1, sub = 0;
	rep(i, m) {
		sub += a / b;
		if (i+1 < m) {
			a *= (n-i);
			b *= (i+1);
		}
	}
	mint res = mint(2).pow(n) - sub;
	cout << res.val() << endl;
	return 0;
}
