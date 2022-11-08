// 解説AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const ll mod = 998244353LL;
ll gcd(ll a, ll b) { return (b ? gcd(b, a%b) : a); }
ll lcm(ll a, ll b) { return (a / gcd(a, b) * b); }

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t0;
	cin >> t0;
	rep(i0, t0) {
		int n, m;
		cin >> n >> m;
		vector<int> a(n);
		rep(i, n) cin >> a[i];
		ll res = 1;
		rep3(i, 1, n) {
			if (a[i-1]%a[i] != 0) {
				res = 0;
				break;
			}
			vector<int> plst;
			int dval = a[i-1] / a[i];
			for (int j=2; j*j<=dval; ++j) if (dval%j == 0) {
				plst.push_back(j);
				while (dval%j == 0) dval /= j;
			}
			if (dval > 1) plst.push_back(dval);
			int bi = plst.size(), tar = m / a[i], nval = m / a[i];
			if (bi > 0) {
				int sval = 0;
				rep3(i1, 1, 1<<bi) {
					ll mval = 1;
					rep(j1, bi) if (i1&(1<<j1)) {
						mval *= plst[j1];
						if (mval > tar) break;
					}
					if (mval > tar) continue;
					if (__builtin_popcount(i1)%2 == 1) sval += tar / mval;
					else sval -= tar / mval;
				}
				nval -= sval;
			}
			res = res * nval % mod;
		}
		cout << res << endl;
	}
	return 0;
}
